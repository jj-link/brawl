#include <revolution/OS/OSError.h>
#pragma force_active on
extern "C" int fn_803EC22C(int, int);
extern "C" int fn_803EBE4C();
extern "C" char lbl_80421474[];
struct Object { unsigned int pad[5]; unsigned int field : 8; unsigned int rest : 24; };
extern "C" int fn_8001EB94(Object* arg) {
    int error = fn_803EC22C(0x41, 0);
    int result;
    if (error != 0) {
        fn_803EBE4C();
        result = 15;
        OSReport(lbl_80421474, error);
    } else {
        result = 0;
    }
    arg->field = result;
    return result;
}