#include <string.h>
#pragma force_active on

extern "C" int fn_803C3B18(const char*);

extern "C" int fn_8001BD04(const char* path) {
    int result;
    char buffer[128];

    if (strlen(path) < 127U) {
        result = fn_803C3B18(path);
        if (result != 0 && result != 17) {
            unsigned int position;
            unsigned int length = strlen(path);
            if (*(path + length - 1) == '/') {
                --length;
            }

            position = 3;
            while (position < length) {
                strcpy(buffer, path);
                for (unsigned int i = position; i < length; ++i) {
                    position = i + 1;
                    if (buffer[i] == '/') {
                        buffer[i] = 0;
                        break;
                    }
                }

                result = fn_803C3B18(buffer);
                if (result != 0 && result != 17) {
                    break;
                }
            }
        }
    }

    return result;
}
