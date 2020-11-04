# Generated Makefile -- DO NOT EDIT!

AR=C:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/HostX86/x64/lib.exe
CC=C:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/HostX86/x64/cl.exe
COMPILER_PREFIX=
DEPGEN=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/mabu/tools/win/depgen.py
HOST=win64
PYTHON=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/python3/python.exe
RM=rm
SPEC=debug_win_msvc-2017-15.9_x64
glad_ARFLAGS=
glad_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
glad_CFLAGS=-MDd -Gm- -ZI -Od -W2
glad_CPPFLAGS=-I$(glad_BASE)/glad/include -IC:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/ATLMFC/include -IC:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/include -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/ucrt -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/shared -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/um -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/winrt -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/cppwinrt -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES
glad_OUTPUT=$(glad_BASE)/.out/$(SPEC)

$(glad_OUTPUT)/glad.lib : $(glad_OUTPUT)/obj.glad/glad/src/glad.c.o $(glad_BASE)/glad.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/standard-c++/11.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[glad\]\ Linking\ static\ library\ 'glad.lib'....
	$(ECHO) $(RM) -f $(glad_OUTPUT)/glad.lib
	$(ECHO) cd $(glad_OUTPUT) && $(AR) -nologo -out:glad.lib obj.glad/glad/src/glad.c.o $(glad_ARFLAGS)

$(glad_OUTPUT)/obj.glad/glad/src/glad.c.o : $(glad_BASE)/glad/src/glad.c $(glad_BASE)/glad.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/standard-c++/11.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[glad\]\ Compiling\ 'glad.c'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(glad_BASE)/glad/src/glad.c $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d $(glad_OUTPUT)/obj.glad/glad/src/glad.c.o -I$(glad_BASE)/glad/include -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES
	$(ECHO) $(COMPILER_PREFIX) $(CC) -nologo -TC -c $(glad_BASE)/glad/src/glad.c -Fo$(glad_OUTPUT)/obj.glad/glad/src/glad.c.o -FS -Fd$(glad_OUTPUT)/glad.pdb $(glad_CPPFLAGS) $(glad_CFLAGS)

-include $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d

glad-clean :: 
	$(INFO) Cleaning\ glad...
	$(ECHO) $(RM) -rf $(glad_OUTPUT)/glad.lib $(glad_OUTPUT)/glad.ilk $(glad_OUTPUT)/glad.idb $(glad_OUTPUT)/glad.pdb $(glad_OUTPUT)/obj.glad/glad/src/glad.c.o
	$(ECHO) $(RM) -rf $(glad_OUTPUT)/obj.glad/glad/src/glad.c.d

glad-all :: -make-directories $(glad_OUTPUT)/glad.lib

