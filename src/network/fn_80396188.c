#include <types.h>
#pragma force_active on

extern void fn_803974FC(void);
extern int fn_80397580(void);
extern int fn_803970DC(int a, int b);
extern int fn_80397094(int a, int b);

int fn_80396188(int arg0) {
    int val;
    int result;
    int ptr;
    fn_803974FC();
    val = fn_80397580();
    result = fn_803970DC(val, arg0);
    if (result != 0) {
        ptr = fn_80397094(val, result);
        if (ptr != 0) {
            return *(int *)((char *)ptr + 0x438);
        }
        return 0;
    }
    return 0;
}
