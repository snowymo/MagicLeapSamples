# Generated Makefile -- DO NOT EDIT!

AR=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/toolchains/llvm-8/bin/aarch64-linux-android-gcc-ar.exe
CC=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/toolchains/llvm-8/bin/aarch64-linux-android-clang
COMPILER_PREFIX=
HOST=win64
RM=rm
SPEC=debug_lumin_clang-8.0_aarch64
TOUCH=touch
glad_ARFLAGS=
glad_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
glad_CFLAGS=--sysroot=$(MLSDK)/lumin/sysroot -march=armv8-a -mcpu=cortex-a57+crypto -fpic -ffunction-sections -funwind-tables -fstack-protector-strong -no-canonical-prefixes -Wa,--noexecstack -Wformat -Werror=format-security -Wno-invalid-command-line-argument -Wno-unused-command-line-argument -g -fno-limit-debug-info -O0
glad_CPPFLAGS=-I$(glad_BASE)/glad/include -DML_LUMIN
glad_OUTPUT=$(glad_BASE)/.out/$(SPEC)

$(glad_OUTPUT)/libglad.a : $(glad_OUTPUT)/obj.glad/glad/src/glad.c.o $(glad_BASE)/glad.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/standard-c++/11.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[glad\]\ Linking\ static\ library\ 'libglad.a'...
	$(ECHO) $(RM) -f $(glad_OUTPUT)/libglad.a
	$(ECHO) cd $(glad_OUTPUT) && $(AR) crs libglad.a obj.glad/glad/src/glad.c.o $(glad_ARFLAGS)
	$(ECHO) $(TOUCH) $(glad_OUTPUT)/libglad.a

$(glad_OUTPUT)/obj.glad/glad/src/glad.c.o : $(glad_BASE)/glad/src/glad.c $(glad_BASE)/glad.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/standard-c++/11.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[glad\]\ Compiling\ 'glad.c'...
	$(ECHO) $(COMPILER_PREFIX) $(CC) -c $(glad_BASE)/glad/src/glad.c -o $(glad_OUTPUT)/obj.glad/glad/src/glad.c.o -MD -MP -MF $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d $(glad_CPPFLAGS) $(glad_CFLAGS)
	$(ECHO) echo $(glad_BASE)/glad/src/glad.c : >> $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d

-include $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d

glad-clean :: 
	$(INFO) Cleaning\ glad...
	$(ECHO) $(RM) -rf $(glad_OUTPUT)/libglad.a $(glad_OUTPUT)/glad.sym $(glad_OUTPUT)/obj.glad/glad/src/glad.c.o $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d
	$(ECHO) $(RM) -rf $(glad_OUTPUT)/bin/libc++_shared.so

glad-all :: -make-directories $(glad_OUTPUT)/libglad.a

