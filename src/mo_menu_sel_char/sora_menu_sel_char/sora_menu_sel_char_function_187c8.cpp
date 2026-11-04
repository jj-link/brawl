#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
struct TargetData { char pad[0x5c8]; unsigned char f5c8; };
struct SelCharSelf { char pad[0x1b0]; int f1b0; int f1b4; char _1b8[0x08]; int f1c0; char _1c4[0x04]; int f1c8; char _1cc[0x28]; TargetData* f1f4; };
void fn_10_18908(void*, int, int, int, int);
void fn_8004D674(void*, int, short*);
void fn_800D3184(void*, int, short*, int);
extern void* g_muWifiInterfaceTask;
}
extern "C" void fn_10_187C8(void* arg0, int arg1) {
    SelCharSelf* self = (SelCharSelf*)arg0;
    short sp8[9];
    int r;
    fn_10_18908(arg0, arg1, self->f1b4, (int)self->f1f4->f5c8, self->f1c0);
    self->f1c8 = arg1;
    void* task = g_muWifiInterfaceTask;
    if (task != 0) {
        int result = 0;
        if (arg1 < 0)
            goto clear;
        {
            int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            if (state >= 0 && state < 4) result = 1; else result = 0;
            if (result != 0) result = 0;
            else {
                if (state >= 4 && state < 0xc) result = 1; else result = 0;
                if (result != 0) result = 1;
                else {
                    if (state >= 0xc && state < 0x10) r = 1; else r = 0;
                    result = 3;
                    if (r != 0) result = 2;
                }
            }
        }
        if (result == 2)
            fn_8004D674(g_GameGlobal, arg1, sp8);
        else
            goto clear;
        goto done;
clear:
        sp8[0] = 0;
done:
        int f1b0 = self->f1b0;
        fn_800D3184(task, f1b0, sp8, arg1 >= 0 ? arg1 & 0xff : 0x78);
    }
}