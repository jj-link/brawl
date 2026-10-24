#include <revolution/FA.h>
#pragma force_active on

extern "C" {

int fn_803EBE4C(void);

int fn_8001FAD8(const char* pattern) {
    char sp8[0x444];
    int var_r31;
    int var_r3;

    var_r31 = -1;
    var_r3 = FAFsfirst(pattern, 0x20, (FAEntryInfo*)sp8);
    if (var_r3 != 0) {
        if (fn_803EBE4C() != 2) {
            fn_803EBE4C();
        }
    } else {
        var_r31 = 1;
        while (var_r3 == 0) {
            var_r3 = FAFsnext((FAEntryInfo*)sp8);
            if (var_r3 != 0) {
                if (fn_803EBE4C() != 2) {
                    fn_803EBE4C();
                }
                break;
            }
            var_r31 += 1;
        }
    }
    return var_r31;
}

}
