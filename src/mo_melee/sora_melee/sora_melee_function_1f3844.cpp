#include <types.h>
#pragma force_active on

struct AiParameterData;

struct AiInput {
    char pad0[0x90];
    AiParameterData* paramData;
    char pad94[0x7C];
    s8 targetId;
    s8 targetSelected;
    char pad112;
    u8 unk113;
    u8 unk114;
    char pad115;
    u16 flags116;
    float value118;
};

struct AiMgrData {
    u8 pad[0x20];
    u8 entries[0x64];
};

extern "C" {
void fn_27_1FAD54(AiInput* self);
AiMgrData* fn_27_1F21B8(void);
}

extern "C" void fn_27_1F3844(AiInput* self, s32 mode) {
    if (mode >= 0 && mode < 0x1D) {
        if (self->unk113 != mode && self->paramData != 0) {
            fn_27_1FAD54(self);
        }
        self->unk113 = (u8)mode;
    }
    AiMgrData* data = fn_27_1F21B8();
    if (data) {
        u8* p = (u8*)data;
        if (self->unk113 < 0x19) {
            p += self->unk113 * 4;
            p += 0x20;
        } else {
            p += 0x20;
        }
        self->flags116 = *(u16*)p;
        self->unk114 = p[2];
    }
}
