#include <types.h>
#pragma force_active on

extern "C" {
extern char* lbl_27_bss_5668;
void fn_27_229C94(char* obj, int flag);

struct fn_27_229C1C_flags {
    u32 pad : 24;
    s32 val : 8;
};

void fn_27_229C1C(char* unused, int flag) {
    if (flag != 0)
        return;
    char* stage = lbl_27_bss_5668;
    char* sub = *(char**)(stage + 0xc4);
    if (sub == 0)
        return;
    fn_27_229C1C_flags* f = (fn_27_229C1C_flags*)(sub + 0x40);
    if (f->val != 1)
        return;
    fn_27_229C94(sub, 0);
}
}
