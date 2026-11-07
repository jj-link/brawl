#pragma force_active on
#include <types.h>

extern void fn_80209850(u32 arg0);
extern int fn_8020981C(void);

void fn_80209F1C(int *arg0, int *arg1) {
    if (arg0 != NULL) {
        fn_80209850(arg0[6]);
        while (fn_8020981C() != 0);
        fn_80209850(arg0[7]);
        while (fn_8020981C() != 0);
        fn_80209850(arg0[8]);
        while (fn_8020981C() != 0);
    } else {
        fn_80209850(0);
        while (fn_8020981C() != 0);
        fn_80209850(0);
        while (fn_8020981C() != 0);
        fn_80209850(0);
        while (fn_8020981C() != 0);
    }
    fn_80209850(arg1[3]);
    while (fn_8020981C() != 0);
    fn_80209850(arg1[4]);
    while (fn_8020981C() != 0);
    fn_80209850(arg1[5]);
    while (fn_8020981C() != 0);
    if (arg1[0] == 0) {
        fn_80209850(*(unsigned short *)((char *)arg1 + 0x24));
        while (fn_8020981C() != 0);
        fn_80209850(0);
        while (fn_8020981C() != 0);
        fn_80209850(0);
        while (fn_8020981C() != 0);
        fn_80209850(0);
        while (fn_8020981C() != 0);
    } else {
        fn_80209850(*(unsigned short *)((char *)arg1 + 0x26));
        while (fn_8020981C() != 0);
        fn_80209850(arg1[6]);
        while (fn_8020981C() != 0);
        fn_80209850(arg1[7]);
        while (fn_8020981C() != 0);
        fn_80209850(arg1[8]);
        while (fn_8020981C() != 0);
    }
}