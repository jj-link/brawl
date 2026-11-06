#include <gf/gf_homemenu.h>
#pragma force_active on

extern "C" {
extern char lbl_804953D0[];
void fn_800368C8(void*);
void* fn_8003682C(void*, int);
void* __register_global_object(void*, void* (*)(void*, int), void*);

gfHomeMenu* fn_800367C8() {
    char* base = lbl_804953D0;
    if ((signed char)base[0x130] == 0) {
        fn_800368C8(base + 0x140);
        __register_global_object(base + 0x140, fn_8003682C, base + 0x134);
        base[0x130] = 1;
    }
    return g_gfHomeMenu = (gfHomeMenu*)(base + 0x140);
}
}
