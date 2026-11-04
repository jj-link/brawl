#include <string.h>
#pragma force_active on

extern "C" int fn_8014DD34(void *, int);
extern "C" int fn_803A3324(void *);
extern "C" int fn_803A2910(void *, int);
extern "C" int fn_803A3058(void *, char *, int);
extern "C" char lbl_80460F48[];

extern "C" int fn_8014D794(void *self) {
    unsigned int entry[128];
    char buffer[128];
    if (fn_8014DD34(self, 1) == 0) return 0;
    if (fn_803A3324(entry) != 0) return 0;
    if (fn_803A2910(entry, 0) != 0) return 0;
    buffer[0] = 0;
    if (fn_803A3058(entry, buffer, 0x80) != 0 ||
        strncmp(buffer, lbl_80460F48, strlen(lbl_80460F48)) != 0) return 0;
    return 1;
}