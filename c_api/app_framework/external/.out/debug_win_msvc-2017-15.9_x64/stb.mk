# Generated Makefile -- DO NOT EDIT!

AR=C:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/HostX86/x64/lib.exe
COMPILER_PREFIX=
CXX=C:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/HostX86/x64/cl.exe
DEPGEN=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/mabu/tools/win/depgen.py
HOST=win64
PYTHON=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/python3/python.exe
RM=rm
SPEC=debug_win_msvc-2017-15.9_x64
stb_ARFLAGS=
stb_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
stb_CPPFLAGS=-I$(stb_BASE)/stb-master/ -IC:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/ATLMFC/include -IC:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/include -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/ucrt -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/shared -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/um -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/winrt -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/cppwinrt -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES
stb_CXXFLAGS=-MDd -Gm- -ZI -Od -EHsc -W2
stb_OUTPUT=$(stb_BASE)/.out/$(SPEC)

$(stb_OUTPUT)/stb.lib : $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o $(stb_BASE)/stb.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[stb\]\ Linking\ static\ library\ 'stb.lib'....
	$(ECHO) $(RM) -f $(stb_OUTPUT)/stb.lib
	$(ECHO) cd $(stb_OUTPUT) && $(AR) -nologo -out:stb.lib obj.stb/stb_lib/stblib.cpp.o $(stb_ARFLAGS)

$(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o : $(stb_BASE)/stb_lib/stblib.cpp $(stb_BASE)/stb.mabu $(MLSDK)/samples/c_api/app_framework/common.comp $(MLSDK)/tools/mabu/data/components/stdc++.comp $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[stb\]\ Compiling\ 'stblib.cpp'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(stb_BASE)/stb_lib/stblib.cpp $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o -I$(stb_BASE)/stb-master/ -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -nologo -TP -c $(stb_BASE)/stb_lib/stblib.cpp -Fo$(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o -FS -Fd$(stb_OUTPUT)/stb.pdb $(stb_CPPFLAGS) $(stb_CXXFLAGS)

-include $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d

stb-clean :: 
	$(INFO) Cleaning\ stb...
	$(ECHO) $(RM) -rf $(stb_OUTPUT)/stb.lib $(stb_OUTPUT)/stb.ilk $(stb_OUTPUT)/stb.idb $(stb_OUTPUT)/stb.pdb $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.o
	$(ECHO) $(RM) -rf $(stb_OUTPUT)/obj.stb/stb_lib/stblib.cpp.d

stb-all :: -make-directories $(stb_OUTPUT)/stb.lib

