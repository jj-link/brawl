#include <types.h>
#pragma force_active on

extern void *fn_803974FC(void);
extern int fn_80397580(void);
extern void *fn_803970DC(int a, int b);
extern int fn_80391A20(void *a, int b);

int fn_8039602C(int arg0) {
    void *temp_r31;
    void *temp_r3;
    int val;

    temp_r31 = fn_803974FC();
    temp_r3 = fn_803970DC(fn_80397580(), arg0);
    if (temp_r3 == 0) {
        return -1;
    }
    val = *(int *)((char *)temp_r3 + 0x18);
    if (val >= 0) {
        fn_80391A20(temp_r31, val);
        return 0;
    }
    return -1;
}
