#pragma force_active on
#include <gf/gf_pad_system.h>
struct Self { unsigned char pad0[0x40]; int value40; int delay44; int unk48; int retries4c; unsigned char pad50[0x80]; int result; int status; unsigned char flag; };
extern "C" int fn_16_6E10();
extern "C" int fn_803F6150(const void*, const void*, unsigned long);
extern "C" void fn_16_74B8(Self* self) {
    if (self->flag != 0) {
        int result = fn_16_6E10();
        if (result == 1) return;
        if (result == 0 && fn_803F6150((char*)self + 0x50, (char*)self + 0x90, 0x40) == 0) {
            self->result = 0; self->status = 0; return;
        }
        if (self->retries4c >= 3) { self->result = 6; self->status = 0; return; }
        g_gfPadSystem->writeGameDataRequest((int)(unsigned char)self->value40, (int)((char*)self + 0x90), 0x40, 0);
        self->flag = 0; self->delay44 = 0; self->retries4c++;
    } else {
        if (self->delay44 > 0) {
            self->delay44--;
            if (self->delay44 <= 0)
                g_gfPadSystem->writeGameDataRequest((int)(unsigned char)self->value40, (int)((char*)self + 0x90), 0x40, 0);
        } else {
            int retry;
            if ((((unsigned char)g_gfPadSystem->_0x35 >> 7) & 1) == 0) retry = 1;
            else {
                retry = 0;
                if (g_gfPadSystem->m_gameData != 0) retry = 6;
            }
            if (retry != 1) {
                if (retry == 0) {
                    self->unk48 = 0; self->delay44 = 0;
                    g_gfPadSystem->readGameDataRequest((int)(unsigned char)self->value40, (int)((char*)self + 0x50), 0x40, 0);
                    self->result = 1; self->flag = 1;
                } else if (self->retries4c >= 3) {
                    self->result = retry; self->status = 0;
                } else {
                    self->retries4c++; self->delay44 = 5;
                }
            }
        }
    }
}