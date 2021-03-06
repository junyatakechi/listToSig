/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"
#include "headers/opus.h"

using namespace c74::min;


class ext_listToSig : public object<ext_listToSig> {
public:
    MIN_DESCRIPTION    {"Opus decoder from list payload."};
    MIN_TAGS        {"utilities"};
    MIN_AUTHOR        {"junyatakechi"};
    MIN_RELATED        {"print, jit.print, dict.print"};
	
    inlet<> input {this, "(list) recieved opus payload.", "list"};
    outlet<> output {this, "(signal) output the decoded sound.", "signal"};
	
	
    // define an optional argument for setting the message
    argument<symbol> greeting_arg { this, "greeting", "Initial value for the greeting attribute.",
        MIN_ARGUMENT_FUNCTION {
            greeting = arg;
        }
    };
	
	
    // the actual attribute for the message
    attribute<symbol> greeting { this, "greeting", "hello world",
        description {
            "Greeting to be posted. "
            "The greeting will be posted to the Max console when a bang is received."
        }
    };
	
	
    //constructors
    ext_listToSig(const atoms& args = {}){
        //cout << "初期化！" << endl;
        buf = (double *)calloc(960, sizeof(double));
        play_point = buf_length - 128;
			
				//opus init
				dec = opus_decoder_create(48000, 1, &err);
				//cout << err << endl;
				if(err!= -1){
						cout << "DECODER CREATED!" << endl;
				}else{
						cout << "error: opus init" << endl;
				}
    };
	
    // respond to the bang message to do something
    message<> bang { this, "bang", "Post the greeting.",
        MIN_FUNCTION {
            symbol the_greeting = greeting;
            cout << the_greeting << endl;
            output.send(the_greeting);
            return {};
        }
    };
    
    message<> number { this, "float",
        MIN_FUNCTION {
            int buf_msec = args[0];
            if (buf_msec < 20) {
                buf_msec = 20;
            }
            unsigned long buf_size =  buf_msec * 48;
            free(buf);
            buf = (double *)calloc(buf_size, sizeof(double));
            play_point = buf_length - 128;
            rec_point = 0;
            cout << "buf_msec is " << buf_msec << endl;
            return {};
        }
     };

    
    // signal process
    void operator()(audio_bundle input, audio_bundle output){
        auto out = output.samples(0);
			
        for(auto i = 0; i < input.frame_count(); ++i){
            if (labs(rec_point - play_point) > 128){
                out[i] = buf[play_point];
                play_point++;
            }else{
                out[i] = buf[play_point]; // output signal
            }
					
            if(play_point > buf_length){
                play_point = 0;
            }
        }
    };
    
    
					
    message<threadsafe::yes> list { this, "list", "Operate on the list. Either add it to the collection or calculate the mean.",
        MIN_FUNCTION{
					
						//!!!!!!!!!!Opus decoding!!!!!!!!!!!!!!!!!!!!!!!
						//the maximum packet duration 120ms; 5760 for 48kHz
						unsigned char payload[960];
						signed int castInt;
						auto i = 0;
						for(double a : args){
								castInt = (signed int)a;
								payload[i] = (unsigned char)castInt;
								i++;
								//cout << payload[i] << endl;
						}

						float samps_len;
						float pcm[960];
						samps_len = opus_decode_float(dec, payload, i, pcm, 960, 0);
						//cout << "samps_len is " << samps_len << endl;
					
						//!!!!!!!!!!END Opus decoding!!!!!!!!!!!!!!!!!!!!!!!
            for(double x : args){
                //cout << x << endl;
                buf[rec_point] = x;
								//cout << rec_point << endl;
                rec_point++;
                if(rec_point > buf_length){
                    rec_point = 0;
                }
            }
            return {};
        }
    };

private:
	double *buf;
	unsigned long buf_length = 960;
	long rec_point = 0;
	long play_point = 0;
	//Opus decoder
	OpusDecoder *dec;
	int err = 0;
				
	//lib::sync m_oscillator;
};

MIN_EXTERNAL(ext_listToSig);
