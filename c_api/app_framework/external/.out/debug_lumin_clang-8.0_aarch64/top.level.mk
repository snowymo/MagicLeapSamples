# Generated Makefile -- DO NOT EDIT!

HOST=win64
SPEC=debug_lumin_clang-8.0_aarch64
app_framework_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework
app_framework_OUTPUT=$(app_framework_BASE)/.out/$(SPEC)
audio_input_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
audio_output_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
bluetooth_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
connections_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
controller_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
eye_tracking_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
glad_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
glad_OUTPUT=$(glad_BASE)/.out/$(SPEC)
hand_tracking_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
head_tracking_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
image_capture_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
image_tracking_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
imgui_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
imgui_OUTPUT=$(imgui_BASE)/.out/$(SPEC)
lifecycle_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
locale_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
location_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
meshing_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
pcf_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
planes_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
raycast_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
samples_common_comp_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples
simple_gl_app_OUTPUT=$(samples_common_comp_BASE)/BUILD/$(SPEC)
stb_BASE=C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external
stb_OUTPUT=$(stb_BASE)/.out/$(SPEC)


# this turns off the suffix rules built into make
.SUFFIXES:

# this turns off the RCS / SCCS implicit rules of GNU Make
% : RCS/%,v
% : RCS/%
% : %,v
% : s.%
% : SCCS/s.%

# If a rule fails, delete $@.
.DELETE_ON_ERROR:

ifeq ($(VERBOSE),)
ECHO=@
else
ECHO=
endif

ifeq ($(QUIET),)
INFO=@echo
else
INFO=@:
endif

ifeq ($(VERBOSE),)
SPAM=@: \#
else
SPAM=@echo
endif

all : prebuild build postbuild

prebuild :: 

postbuild :: 

clean :: stb-clean imgui-clean glad-clean app_framework-clean location-clean planes-clean simple_gl_app-clean pcf-clean bluetooth-clean eye_tracking-clean audio_output-clean meshing-clean head_tracking-clean audio_input-clean controller-clean hand_tracking-clean locale-clean image_tracking-clean raycast-clean connections-clean lifecycle-clean image_capture-clean

$(MLSDK)/tools/mabu/data/options/optimize/off.option : 

$(MLSDK)/tools/mabu/data/components/stdc++.comp : 

$(MLSDK)/.metadata/components/ml_sdk_common.comp : 

$(MLSDK)/samples/c_api/app_framework/external/glm.comp : 

$(MLSDK)/tools/mabu/data/configs/debug.config : 

$(MLSDK)/samples/c_api/app_framework/common.comp : 

$(MLSDK)/tools/mabu/data/options/standard-c++/11.option : 

$(MLSDK)/tools/mabu/data/options/package/debuggable/on.option : 

$(MLSDK)/samples/c_api/app_framework/external/assimp.comp : 

$(MLSDK)/samples/c_api/samples/samples_common.comp : 

$(MLSDK)/tools/mabu/data/options/warn/on.option : 

$(MLSDK)/tools/mabu/data/options/debug/on.option : 

$(MLSDK)/tools/mabu/data/components/OpenGL.comp : 

$(MLSDK)/tools/mabu/data/options/magicleap.option : 

$(MLSDK)/.metadata/components/ml_sdk.comp : 

$(MLSDK)/samples/c_api/app_framework/external/gflags.comp : 

$(MLSDK)/tools/mabu/data/options/runtime/shared.option : 

PROGRAM_PREFIX=
PROGRAM_EXT=
SHARED_PREFIX=lib
SHARED_EXT=.so
IMPLIB_PREFIX=lib
IMPLIB_EXT=.so
STATIC_PREFIX=lib
STATIC_EXT=.a
COMPILER_PREFIX=
LINKER_PREFIX=

-make-directories : C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64 C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/bin C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/device C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/input C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/render C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64 C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/bin C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.glad/glad/src C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.imgui/imgui-1.68 C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.imgui/imgui-1.68/examples C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.stb/stb_lib C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64 C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/bin C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/data C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.audio_input C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.audio_output C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.bluetooth C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.connections C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.controller C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.eye_tracking C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.hand_tracking C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.head_tracking C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.image_capture C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.image_tracking C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.lifecycle C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.locale C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.location C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.meshing C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.pcf C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.planes C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.raycast C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.simple_gl_app

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64 : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/bin : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/bin

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/device : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/device

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/input : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/input

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/render : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/.out/debug_lumin_clang-8.0_aarch64/obj.app_framework/src/render

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64 : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/bin : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/bin

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.glad/glad/src : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.glad/glad/src

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.imgui/imgui-1.68 : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.imgui/imgui-1.68

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.imgui/imgui-1.68/examples : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.imgui/imgui-1.68/examples

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.stb/stb_lib : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/app_framework/external/.out/debug_lumin_clang-8.0_aarch64/obj.stb/stb_lib

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64 : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/bin : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/bin

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/data : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/data

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.audio_input : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.audio_input

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.audio_output : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.audio_output

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.bluetooth : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.bluetooth

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.connections : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.connections

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.controller : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.controller

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.eye_tracking : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.eye_tracking

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.hand_tracking : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.hand_tracking

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.head_tracking : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.head_tracking

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.image_capture : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.image_capture

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.image_tracking : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.image_tracking

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.lifecycle : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.lifecycle

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.locale : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.locale

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.location : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.location

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.meshing : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.meshing

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.pcf : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.pcf

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.planes : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.planes

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.raycast : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.raycast

C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.simple_gl_app : 
	$(ECHO) @mkdir -p C:/Users/snowy/MagicLeap/mlsdk/v0.24.1/samples/c_api/samples/BUILD/debug_lumin_clang-8.0_aarch64/obj.simple_gl_app

include $(stb_OUTPUT)/stb.mk
include $(imgui_OUTPUT)/imgui.mk
include $(glad_OUTPUT)/glad.mk
include $(app_framework_OUTPUT)/app_framework.mk
include $(location_OUTPUT)/location.mk
include $(planes_OUTPUT)/planes.mk
include $(simple_gl_app_OUTPUT)/simple_gl_app.mk
include $(pcf_OUTPUT)/pcf.mk
include $(bluetooth_OUTPUT)/bluetooth.mk
include $(eye_tracking_OUTPUT)/eye_tracking.mk
include $(audio_output_OUTPUT)/audio_output.mk
include $(meshing_OUTPUT)/meshing.mk
include $(head_tracking_OUTPUT)/head_tracking.mk
include $(audio_input_OUTPUT)/audio_input.mk
include $(controller_OUTPUT)/controller.mk
include $(hand_tracking_OUTPUT)/hand_tracking.mk
include $(locale_OUTPUT)/locale.mk
include $(image_tracking_OUTPUT)/image_tracking.mk
include $(raycast_OUTPUT)/raycast.mk
include $(connections_OUTPUT)/connections.mk
include $(lifecycle_OUTPUT)/lifecycle.mk
include $(image_capture_OUTPUT)/image_capture.mk
build :  | stb-all imgui-all glad-all app_framework-all location-all planes-all simple_gl_app-all pcf-all bluetooth-all eye_tracking-all audio_output-all meshing-all head_tracking-all audio_input-all controller-all hand_tracking-all locale-all image_tracking-all raycast-all connections-all lifecycle-all image_capture-all

