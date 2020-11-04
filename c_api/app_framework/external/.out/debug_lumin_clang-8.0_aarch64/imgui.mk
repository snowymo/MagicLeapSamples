# Generated Makefile -- DO NOT EDIT!

AR=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/toolchains/llvm-8/bin/aarch64-linux-android-gcc-ar.exe
COMPILER_PREFIX=
CXX=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/tools/toolchains/llvm-8/bin/aarch64-linux-android-clang++
HOST=win64
RM=rm
SPEC=debug_lumin_clang-8.0_aarch64
TOUCH=touch
glad_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
imgui_ARFLAGS=
imgui_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
imgui_CPPFLAGS=-I$(imgui_BASE)/imgui-1.68 -I$(glad_BASE)/glad/include -DML_LUMIN -DIMGUI_IMPL_OPENGL_LOADER_GLAD
imgui_CXXFLAGS=--sysroot=$(MLSDK)/lumin/sysroot -march=armv8-a -mcpu=cortex-a57+crypto -fPIC -fpic -ffunction-sections -funwind-tables -fstack-protector-strong -no-canonical-prefixes -Wa,--noexecstack -Wformat -Werror=format-security -Wno-invalid-command-line-argument -Wno-unused-command-line-argument -g -fno-limit-debug-info -O0 -nostdinc++ -I$(MLSDK)/lumin/stl/libc++-8/include -std=c++11 -fexceptions
imgui_OUTPUT=$(imgui_BASE)/.out/$(SPEC)

$(imgui_OUTPUT)/libimgui.a : $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Linking\ static\ library\ 'libimgui.a'...
	$(ECHO) $(RM) -f $(imgui_OUTPUT)/libimgui.a
	$(ECHO) cd $(imgui_OUTPUT) && $(AR) crs libimgui.a obj.imgui/imgui-1.68/imgui.cpp.o obj.imgui/imgui-1.68/imgui_demo.cpp.o obj.imgui/imgui-1.68/imgui_draw.cpp.o obj.imgui/imgui-1.68/imgui_widgets.cpp.o obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o $(imgui_ARFLAGS)
	$(ECHO) $(TOUCH) $(imgui_OUTPUT)/libimgui.a

$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o : $(imgui_BASE)/imgui-1.68/imgui.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui.cpp'...
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -c $(imgui_BASE)/imgui-1.68/imgui.cpp -o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o -MD -MP -MF $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)
	$(ECHO) echo $(imgui_BASE)/imgui-1.68/imgui.cpp : >> $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o : $(imgui_BASE)/imgui-1.68/imgui_demo.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_demo.cpp'...
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -c $(imgui_BASE)/imgui-1.68/imgui_demo.cpp -o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o -MD -MP -MF $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)
	$(ECHO) echo $(imgui_BASE)/imgui-1.68/imgui_demo.cpp : >> $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o : $(imgui_BASE)/imgui-1.68/imgui_draw.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_draw.cpp'...
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -c $(imgui_BASE)/imgui-1.68/imgui_draw.cpp -o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o -MD -MP -MF $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)
	$(ECHO) echo $(imgui_BASE)/imgui-1.68/imgui_draw.cpp : >> $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o : $(imgui_BASE)/imgui-1.68/imgui_widgets.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_widgets.cpp'...
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -c $(imgui_BASE)/imgui-1.68/imgui_widgets.cpp -o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o -MD -MP -MF $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)
	$(ECHO) echo $(imgui_BASE)/imgui-1.68/imgui_widgets.cpp : >> $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d
$(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o : $(imgui_BASE)/imgui-1.68/examples/imgui_impl_opengl3.cpp $(imgui_BASE)/imgui.mabu $(MLSDK)/tools/mabu/data/configs/debug.config $(MLSDK)/tools/mabu/data/options/debug/on.option $(MLSDK)/tools/mabu/data/options/magicleap.option $(MLSDK)/tools/mabu/data/options/optimize/off.option $(MLSDK)/tools/mabu/data/options/package/debuggable/on.option $(MLSDK)/tools/mabu/data/options/runtime/shared.option $(MLSDK)/tools/mabu/data/options/warn/on.option
	$(INFO) \[imgui\]\ Compiling\ 'imgui_impl_opengl3.cpp'...
	$(ECHO) $(COMPILER_PREFIX) $(CXX) -c $(imgui_BASE)/imgui-1.68/examples/imgui_impl_opengl3.cpp -o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o -MD -MP -MF $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d $(imgui_CPPFLAGS) $(imgui_CXXFLAGS)
	$(ECHO) echo $(imgui_BASE)/imgui-1.68/examples/imgui_impl_opengl3.cpp : >> $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d

-include $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d

imgui-clean :: 
	$(INFO) Cleaning\ imgui...
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/libimgui.a $(imgui_OUTPUT)/imgui.sym $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui.cpp.d
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_demo.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_draw.cpp.d
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/imgui_widgets.cpp.d $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.o $(imgui_OUTPUT)/obj.imgui/imgui-1.68/examples/imgui_impl_opengl3.cpp.d
	$(ECHO) $(RM) -rf $(imgui_OUTPUT)/bin/libc++_shared.so

imgui-all :: -make-directories $(imgui_OUTPUT)/libimgui.a

