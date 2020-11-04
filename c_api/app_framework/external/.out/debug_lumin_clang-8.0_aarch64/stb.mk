# Generated Makefile -- DO NOT EDIT!

AR=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/toolchains/llvm-8/bin/aarch64-linux-android-gcc-ar.exe
COMPILER_PREFIX=
CXX=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/toolchains/llvm-8/bin/aarch64-linux-android-clang++
HOST=win64
RM=rm
SPEC=debug_lumin_clang-8.0_aarch64
TOUCH=touch
stb_ARFLAGS=
stb_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
stb_CPPFLAGS=-I$(stb_BASE)/stb-master/ -DML_LUMIN
stb_CXXFLAGS=--sysroot=$(MLSDK)/lumin/sysroot -march=armv8-a -mcpu=cortex-a57+crypto -fpic -ffunction-sections -funwind-tables -fstack-protector-strong -no-canonical-prefixes -Wa,--noexecstack -Wformat -Werror=format-security -Wno-invalid-command-line-argument -Wno-unused-command-line-argument -g -fno-limit-debug-info -O0 -nostdinc++ -I$(MLSDK)/lumin/stl/libc++-8/include -std=c++11 -fexceptions -Wno-parentheses-equality
stb_OUTPUT=$(stb_BASE)/.out/$(SPEC)

$(stb_OUTPUT)/libstb.a : $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o $(stb_BASE)/stb.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[stb\]\ Linking\ static\ library\ 'libstb.a'...
	$(ECHO) $(RM) -f $(stb_OUTPUT)/libstb.a
	$(ECHO) cd $(stb_OUTPUT) && $(AR) crs libstb.a obj.stb/stb_lib/stblib.cpp.o $(stb_ARFLAGS)
	$(ECHO) $(TOUCH) $(stb_OUTPUT)/libstb.a

$(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o : $(stb_BASE)/stb_lib/stblib.cpp $(stb_BASE)/stb.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[stb\]\ Compiling\ 'stblib.cpp'...
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -c $(stb_BASE)/stb_lib/stblib.cpp -o $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o -MD -MP -MF $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d $(stb_CPPFLAGS) $(stb_CXXFLAGS)
	$(ECHO) echo $(stb_BASE)/stb_lib/stblib.cpp : >> $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d

-include $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d

stb-clean :: 
	$(INFO) Cleaning\ stb...
	$(ECHO) $(RM) -rf $(stb_OUTPUT)/libstb.a $(stb_OUTPUT)/stb.sym $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d
	$(ECHO) $(RM) -rf $(stb_OUTPUT)/bin/libc++_shared.so

stb-all :: -make-directories $(stb_OUTPUT)/libstb.a

