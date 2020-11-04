#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gflags::gflags_nothreads_shared" for configuration "Debug"
set_property(TARGET gflags::gflags_nothreads_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gflags::gflags_nothreads_shared PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libgflags_nothreads_debug.so.2.2.2"
  IMPORTED_SONAME_DEBUG "libgflags_nothreads_debug.so.2.2"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags::gflags_nothreads_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags::gflags_nothreads_shared "${_IMPORT_PREFIX}/lib/libgflags_nothreads_debug.so.2.2.2" )

# Import target "gflags::gflags_nothreads_static" for configuration "Debug"
set_property(TARGET gflags::gflags_nothreads_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gflags::gflags_nothreads_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libgflags_nothreads_debug.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags::gflags_nothreads_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags::gflags_nothreads_static "${_IMPORT_PREFIX}/lib/libgflags_nothreads_debug.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
