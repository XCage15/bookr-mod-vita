// TODO: Find a place for this

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>

#include <mupdf/fitz.h>
#include <vita2d.h>

vita2d_texture* _vita2d_load_pixmap_generic(fz_pixmap *pixmap);
const char *get_ext (const char *fspec);

#endif