# Generated by CMake, DO NOT EDIT

empty:= 
space:= $(empty) $(empty)
spaceplus:= $(empty)\ $(empty)

TARGETS += $(subst $(space),$(spaceplus),$(wildcard /Users/Takechi/Documents/Max\ 8/Packages/ext/source/min-api/max-api/script/max-posttarget.cmake))
TARGETS += $(subst $(space),$(spaceplus),$(wildcard /Users/Takechi/Documents/Max\ 8/Packages/ext/source/min-api/max-api/script/max-pretarget.cmake))
TARGETS += $(subst $(space),$(spaceplus),$(wildcard /Users/Takechi/Documents/Max\ 8/Packages/ext/source/min-api/script/min-posttarget.cmake))
TARGETS += $(subst $(space),$(spaceplus),$(wildcard /Users/Takechi/Documents/Max\ 8/Packages/ext/source/min-api/script/min-pretarget.cmake))
TARGETS += $(subst $(space),$(spaceplus),$(wildcard /Users/Takechi/Documents/Max\ 8/Packages/ext/source/min-api/test/min-object-unittest.cmake))
TARGETS += $(subst $(space),$(spaceplus),$(wildcard /Users/Takechi/Documents/Max\ 8/Packages/ext/source/projects/ext.listToSig/CMakeLists.txt))

/Users/Takechi/Documents/Max\ 8/Packages/ext/build/CMakeFiles/cmake.check_cache: $(TARGETS)
	/Users/Takechi/Documents/Max\ 8/Packages/min-devkit/script/cmake-mac/bin/cmake -H/Users/Takechi/Documents/Max\ 8/Packages/ext -B/Users/Takechi/Documents/Max\ 8/Packages/ext/build
