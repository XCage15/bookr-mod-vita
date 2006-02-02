/*
 * Bookr: document reader for the Sony PSP 
 * Copyright (C) 2005 Carlos Carrasco Martinez (carloscm at gmail dot com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdio.h>
#include <list>
using namespace std;

#include "bkpalmdoc.h"
#include "palmdoc/palmdoc.h"

BKPalmDoc::BKPalmDoc() : buffer(0) { }
BKPalmDoc::~BKPalmDoc() {
	if (buffer)
		free(buffer);
}

BKPalmDoc* BKPalmDoc::create(string& file) {
	BKPalmDoc* r = new BKPalmDoc();
	r->fileName = file;
	int length = 0;
	int isMobi = 0;

	// convert file to plain text
	char* b = palmdoc_decode(file.c_str(), &length, &isMobi);
	if (b == NULL) {
		return 0;
	}

	if (isMobi) {
		r->buffer = BKFancyText::parseHTML(r, b, length);
	} else {
		r->buffer = BKFancyText::parseText(r, b, length);
	}

	r->resetFonts();
	r->resizeView(480, 272);
	return r;
}

void BKPalmDoc::getFileName(string& fn) {
	fn = fileName;
}

void BKPalmDoc::getTitle(string& t) {
	t = "FIX PALMDOC TITLES";
}

void BKPalmDoc::getType(string& t) {
	t = "PalmDoc";
}

bool BKPalmDoc::isPalmDoc(string& file) {
	return palmdoc_is_palmdoc(file.c_str()) != 0;
}

