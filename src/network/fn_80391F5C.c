#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern void fn_8039094C(void);
extern void fn_80390950(int);
extern void fn_803A9130(int);

void fn_80391F5C(int arg0, char *arg1, int arg2) {
    fn_8039094C();
    if (*(int *)(arg1 + 0xAC) > 0) {
        fn_803A9130(*(int *)(arg1 + 0xAC));
        *(int *)(arg1 + 0xAC) = -1;
    }
    fn_80390950(arg0);
    SOClose(arg2);
}
