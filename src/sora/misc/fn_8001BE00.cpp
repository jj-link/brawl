#pragma force_active on
#include <string.h>

#include <gf/gf_file_io.h>

extern "C" int fn_803EC0CC(const char* path);
extern "C" int fn_803EBE4C();

int gfFileIO::gfFACreateDir(const char* filepath) {
    int result;
    char buffer[128];

    if (strlen(filepath) < 127U) {
        result = fn_803EC0CC(filepath);
        if (result != 0) {
            result = fn_803EBE4C();
            if (result != 17) {
                unsigned int position;
                unsigned int length = strlen(filepath);
                if (*(filepath + length - 1) == '/') {
                    --length;
                }

                position = 3;
                while (position < length) {
                    strcpy(buffer, filepath);
                    for (unsigned int i = position; i < length; ++i) {
                        position = i + 1;
                        if (buffer[i] == '/') {
                            buffer[i] = 0;
                            break;
                        }
                    }

                    result = fn_803EC0CC(buffer);
                    if (result != 0) {
                        result = fn_803EBE4C();
                        if (result != 17) {
                            break;
                        }
                    }
                }
            }
        }
    }

    return result;
}
