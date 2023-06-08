/**
 * Copyright (C) 2015 Genome Research Ltd. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @file compat_checksum.c
 * @author Keith James <kdj@sanger.ac.uk>
 */

#include "compat_checksum.h"

#if IRODS_VERSION_INTEGER && IRODS_VERSION_INTEGER >= 4001008
void compat_SHA256Init(SHA256_CTX *context) {
    SHA256_Init(context);
}

void compat_SHA256Update(SHA256_CTX *context, unsigned char *input,
                      unsigned int len) {
    SHA256_Update(context, input, len);
}

void compat_SHA256Final(unsigned char digest[32], SHA256_CTX *context) {
    SHA256_Final(digest, context);
}
#else
void compat_SHA256Init(SHA256_CTX *context) {
    SHA256_Init(context);
}

void compat_SHAUpdate(SHA256_CTX *context, unsigned char *input,
                      unsigned int len) {
    SHA256_Update(context, input, len);
}

void compat_SHA256Final(unsigned char digest[32], SHA256_CTX *context) {
    SHA256_Final(digest, context);
}
#endif
