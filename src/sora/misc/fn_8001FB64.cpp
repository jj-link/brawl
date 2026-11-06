#include <revolution/FA.h>
#include <revolution/OS/OSError.h>
#include <string.h>

#pragma force_active on

extern "C" {

int fn_803EBE4C(void);
extern char lbl_8042153C[];

int fn_8001FB64(const char* pattern, unsigned int dest, int unused, int size) {
    int result;
    char* output = (char*)dest;
    char buffer[0x444];

    if ((result = FAFsfirst(pattern, 0x20, (FAEntryInfo*)buffer)) != 0) {
        if (fn_803EBE4C() != 2) {
            fn_803EBE4C();
        }
    } else {
        {
            char* name = buffer + 0x23a;
            if (*name == 0) {
                name = buffer + 0x22d;
            }

            unsigned int length = strlen(name);
            if (size == 0 || length < (unsigned int)size) {
                strcpy(output, name);
                *(output += length) = 0;
                ++output;
            }
        }

        while (result == 0) {
            result = FAFsnext((FAEntryInfo*)buffer);
            if (result == 0) {
                char* name = buffer + 0x23a;
                if (*name == 0) {
                    name = buffer + 0x22d;
                }

                unsigned int length = strlen(name);
                strcpy(output, name);
                *(output += length) = 0;
                ++output;
            } else {
                if (fn_803EBE4C() != 2) {
                    fn_803EBE4C();
                    OSReport(lbl_8042153C, pattern);
                }
                break;
            }
        }
    }

    return 0;
}

}
