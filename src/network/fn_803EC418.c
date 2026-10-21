#include <types.h>
#pragma force_active on

void OSReport(const char* msg, ...);
void fn_801E039C(void);
extern char lbl_8049318C[];

int fn_803EC418(int arg0) {
    if (arg0 == 0) {
        OSReport(lbl_8049318C);
        return -2;
    }
    fn_801E039C();
    return 0;
}
