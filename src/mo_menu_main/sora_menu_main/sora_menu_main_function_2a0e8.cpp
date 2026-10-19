#pragma force_active on
#include <types.h>
#include <gm/gm_global.h>

extern "C" {
void fn_2_28EB8(void* self);
void fn_2_2A58C(void* self, int flag);
int fn_8004D148(GameGlobal* p);

void fn_2_2A0E8(void* self, int p2, int p3, int p4) {
    int* s = (int*)self;
    s[0x654/4] = p2;
    int* r4 = (int*)s[0x650/4];
    int* r7 = (int*)s[0x64C/4];
    s[0x670/4] = 0;
    s[0x674/4] = 0;
    s[0x678/4] = p3;
    s[0x66C/4] = p4;
    s[0x6A0/4] = 0;
    s[0x694/4] = 0;
    s[0x698/4] = 0;
    s[0x69C/4] = 0;
    s[0x67C/4] = r7[0x28C/4];
    s[0x680/4] = r7[0x290/4];
    s[0x684/4] = r7[0x298/4];
    s[0x688/4] = r7[0x294/4];
    s[0x6B4/4] = r7[0x29C/4];
    s[0x6B8/4] = r7[0x2A0/4];
    s[0x6BC/4] = r7[0x2A4/4];
    s[0x68C/4] = r4[0x4C/4];
    s[0x690/4] = r4[0x50/4];
    fn_2_28EB8(self);
    fn_2_2A58C(self, 0);
    s[0x6A4/4] = fn_8004D148(g_GameGlobal);
}
}
