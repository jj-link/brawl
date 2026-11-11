#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct Flags4924 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct Self {
    char pad00[0x6];
    u8 unk6;
    char pad07;
    s32 unk8;
    char pad0C[0x14];
    u8 unk20;
    char pad21[0x17];
    u8 unk38;
    char pad39[0x1B];
    u8 unk54;
    char pad55[3];
};

extern "C" void fn_40_16090(void* arg0, int arg1);
extern "C" void fn_40_156DC(void* self, void* input, int flag);
extern "C" void fn_40_15A44(void* self, int arg, int flag);
extern "C" void fn_40_15978(void* self, int arg, int flag);

extern "C" void fn_40_15F74(Self* self) {
    u8* item;
    u8* data;
    u8* temp;
    u8* base;
    int i;
    if (self->unk6 != 0) {
        fn_40_16090(self, self->unk8);
        base = (u8*)self;
        item = base;
        data = base + 0x24;
        for (i = 0; i < 2; i++) {
            if (item[0x38] != 0) {
                temp = base + i;
                Flags4924* f = (Flags4924*)((u8*)g_GameGlobal->m_advData + 0x4924);
                bool flag = f->b1;
                if (temp[0x1c] == 0) {
                    fn_40_156DC(self, data, flag);
                    if (temp[0x1e] != 0) {
                        fn_40_15A44(self, i, flag);
                        temp[0x1e] = 0;
                    }
                } else {
                    fn_40_156DC(self, data, flag);
                    fn_40_15978(self, i, flag);
                    item[0x38] = 0;
                }
            }
            item += 0x1c;
            data += 0x1c;
        }
        if (self->unk38 == 0 && self->unk54 == 0) {
            self->unk6 = 0;
        }
    }
}
