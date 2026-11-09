#include <string.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
extern "C" {
int fn_803C3DE0(int*, int, int);
void fn_8001B9E8(void);
int fn_803C3ED8(int*);
extern const char lbl_80421520[];
int fn_8001F84C(int arg0, unsigned int dest, int unused, int size) {
    char buffer[0x444];
    int status;
    int result;
    char* output = (char*)dest;
    result = -1;
    status = fn_803C3DE0((int*)buffer, arg0, 0x20);
    if (status != 0) {
        if (status != 2) fn_8001B9E8();
    } else {
        {
            char* name = buffer + 0x23A;
            if (*name == 0) name = buffer + 0x22D;
            unsigned int length = strlen(name);
            if (size == 0 || length < (unsigned int)size) {
                strcpy(output, name);
                *(output += length) = 0;
                ++output;
            }
        }
        result = 1;
        for (; status == 0; ++result) {
            status = fn_803C3ED8((int*)buffer);
            if (status == 0) {
                char* name = buffer + 0x23A;
                if (*name == 0) name = buffer + 0x22D;
                unsigned int length = strlen(name);
                strcpy(output, name);
                *(output += length) = 0;
                ++output;
            } else {
                if (status != 2) {
                    fn_8001B9E8();
                    OSReport(lbl_80421520, arg0);
                }
                break;
            }
        }
    }
    return result;
}
}