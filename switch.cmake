# TODO: needed Externals switch-freetype

# Add any additional include paths here
include_directories(
  ${CMAKE_BINARY_DIR}
  $ENV{DEVKITPRO}/libnx/include
  $ENV{DEVKITPRO}/portlibs/switch/include
  $ENV{DEVKITPRO}/portlibs/switch/include/freetype2
  ${CMAKE_SOURCE_DIR}/ext/mupdf/src/mupdf_lib/include
  ${CMAKE_SOURCE_DIR}/ext/tinyxml2
  "${SOURCE_DIR}/include"
)

# Add any additional library paths here
# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/ext/mupdf/src/mupdf_lib/build/switch/release
)

add_executable(bookr-modern
  ${COMMON_SRCS}
  ${bk_resources}
  data/fonts/res_txtfont.c
  data/fonts/res_uifont.c

  src/graphics/fzscreen_switch.cpp

  src/graphics/fzfontvita.cpp
  src/filetypes/bkmudocument.cpp
)

# Library to link to (drop the -l prefix). This will mostly be stubs.
#-lpsp2shell -lSceSysmodule_stub -lSceNet_stub \ -lSceNetCtl_stub -lSceKernel_stub -lScePower_stub -lSceAppMgr_stub
#mupdf -ldjvulibre -lraster -lworld -lfonts -lstream -lbase -lm
target_link_libraries(bookr-modern
  mupdf
  mupdfthird
  tinyxml2
)