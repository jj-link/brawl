#include <types.h>
#pragma force_active on

extern void fn_803974FC(void);
extern int fn_80397580(void);
extern int fn_803970DC(int a, int b);
extern int fn_80397094(int a, int b);

int fn_803960EC(int arg0, int *arg1, int *arg2) {
    int val;
    int result;
    int ptr;
    int *p;
    fn_803974FC();
    val = fn_80397580();
    result = fn_803970DC(val, arg0);
    if (result != 0) {
        ptr = fn_80397094(val, result);
        if (ptr != 0) {
            p = (int *)ptr;
            *arg1 = p[10];
            *arg2 = p[7];
            return p[1];
        }
        return -1;
    }
    return -1;
}
