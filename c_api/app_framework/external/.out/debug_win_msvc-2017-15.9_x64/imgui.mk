# Generated Makefile -- DO NOT EDIT!

AR=C:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/HostX86/x64/lib.exe
COMPILER_PREFIX=
CXX=C:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/bin/HostX86/x64/cl.exe
DEPGEN=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/mabu/tools/win/depgen.py
HOST=win64
PYTHON=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/python3/python.exe
RM=rm
SPEC=debug_win_msvc-2017-15.9_x64
glad_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
imgui_ARFLAGS=
imgui_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
imgui_CPPFLAGS=-I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -IC:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/ATLMFC/include -IC:/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Community/VC/Tools/MSVC/14.16.27023/include -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/ucrt -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/shared -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/um -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/winrt -IC:/Program\ Files\ \(x86\)/Windows\ Kits/10/include/10.0.18362.0/cppwinrt -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES -DIMGUI_IMPL_OPENGL_LOADER_GLAD
imgui_CXXFLAGS=-MDd -Gm- -ZI -Od -EHsc -W2
imgui_OUTPUT=$(imgui_BASE)/.out/$(SPEC)

$(imgui_OUTPUT)/imgui.lib : $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Linking\ static\ library\ 'imgui.lib'....
	$(ECHO) $(RM) -f $(imgui_OUTPUT)/imgui.lib
	$(ECHO) cd $(imgui_OUTPUT) && $(AR) -nologo -out:imgui.lib obj.imgui/imgui-1.68/imgui.cpp.o obj.imgui/imgui-1.68/imgui_demo.cpp.o obj.imgui/imgui-1.68/imgui_draw.cpp.o obj.imgui/imgui-1.68/imgui_widgets.cpp.o obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o $(imgui_ARFLAGS)

$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o : $(imgui_BASE)/imgui-1.68/imgui.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui.cpp'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(imgui_BASE)/imgui-1.68/imgui.cpp $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o -I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES -DIMGUI_IMPL_OPENGL_LOADER_GLAD
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -nologo -TP -c $(imgui_BASE)/imgui-1.68/imgui.cpp -Fo$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o -FS -Fd$(imgui_OUTPUT)/imgui.pdb $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o : $(imgui_BASE)/imgui-1.68/imgui_demo.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_demo.cpp'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(imgui_BASE)/imgui-1.68/imgui_demo.cpp $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o -I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES -DIMGUI_IMPL_OPENGL_LOADER_GLAD
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -nologo -TP -c $(imgui_BASE)/imgui-1.68/imgui_demo.cpp -Fo$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o -FS -Fd$(imgui_OUTPUT)/imgui.pdb $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o : $(imgui_BASE)/imgui-1.68/imgui_draw.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_draw.cpp'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(imgui_BASE)/imgui-1.68/imgui_draw.cpp $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o -I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES -DIMGUI_IMPL_OPENGL_LOADER_GLAD
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -nologo -TP -c $(imgui_BASE)/imgui-1.68/imgui_draw.cpp -Fo$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o -FS -Fd$(imgui_OUTPUT)/imgui.pdb $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o : $(imgui_BASE)/imgui-1.68/imgui_widgets.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_widgets.cpp'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(imgui_BASE)/imgui-1.68/imgui_widgets.cpp $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o -I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES -DIMGUI_IMPL_OPENGL_LOADER_GLAD
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -nologo -TP -c $(imgui_BASE)/imgui-1.68/imgui_widgets.cpp -Fo$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o -FS -Fd$(imgui_OUTPUT)/imgui.pdb $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o : $(imgui_BASE)/imgui-1.68/examples/imgui_impl_opengl3.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_impl_opengl3.cpp'...
	$(ECHO) $(PYTHON) $(DEPGEN) $(imgui_BASE)/imgui-1.68/examples/imgui_impl_opengl3.cpp $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o -I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -DML_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOGDI -D_USE_MATH_DEFINES -DIMGUI_IMPL_OPENGL_LOADER_GLAD
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -nologo -TP -c $(imgui_BASE)/imgui-1.68/examples/imgui_impl_opengl3.cpp -Fo$(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o -FS -Fd$(imgui_OUTPUT)/imgui.pdb $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d

imgui-clean :: 
	$(INFO) Cleaning\ imgui...
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/imgui.lib $(imgui_OUTPUT)/imgui.ilk $(imgui_OUTPUT)/imgui.idb $(imgui_OUTPUT)/imgui.pdb $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d

imgui-all :: -make-directories $(imgui_OUTPUT)/imgui.lib

