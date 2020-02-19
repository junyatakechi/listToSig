# CMake generated Testfile for 
# Source directory: /Users/Takechi/Documents/Max 8/Packages/ext/source/projects/ext.listToSig
# Build directory: /Users/Takechi/Documents/Max 8/Packages/ext/build/source/projects/ext.listToSig
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(ext.listToSig_test "/Users/Takechi/Documents/Max 8/Packages/ext/tests/ext.listToSig_test")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(ext.listToSig_test "/Users/Takechi/Documents/Max 8/Packages/ext/tests/ext.listToSig_test")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(ext.listToSig_test "/Users/Takechi/Documents/Max 8/Packages/ext/tests/MinSizeRel/ext.listToSig_test")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(ext.listToSig_test "/Users/Takechi/Documents/Max 8/Packages/ext/tests/RelWithDebInfo/ext.listToSig_test")
else()
  add_test(ext.listToSig_test NOT_AVAILABLE)
endif()
