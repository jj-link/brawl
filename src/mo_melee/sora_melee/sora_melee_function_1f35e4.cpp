#include <types.h>
#pragma force_active on

struct AiParameterData;
struct AiAttackData;

struct AiParameters {
    /* 0x00 */ AiParameterData* unk0;
    /* 0x04 */ AiAttackData* unk4;
    /* 0x08 */ s8 level;
    /* 0x09 */ char pad9[7];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ char pad14[4];
    /* 0x18 */ f32 unk18;
    /* 0x1C */ char pad1C[0xC];
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char pad30[0x14];
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45;
    /* 0x46 */ u8 unk46;
    /* 0x47 */ u8 unk47;
    /* 0x48 */ char pad48[0x38];
};

struct AiScript;

struct AiInput {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ void* unk30;
    /* 0x034 */ AiInput* partner;
    /* 0x038 */ void* scriptBuffer;
    /* 0x03C */ u16 flags;
    /* 0x03E */ u8 unk3E;
    /* 0x03F */ u8 unk3F;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ s8 unk_41;
    /* 0x042 */ s8 fighterId;
    /* 0x043 */ u8 unk43;
    /* 0x044 */ AiScript* script;
    /* 0x048 */ s32 mode;
    /* 0x04C */ char pad4C[0x44];
    /* 0x090 */ AiParameters parameters;
    /* 0x110 */ s8 targetId;
    /* 0x111 */ s8 targetSelected;
    /* 0x112 */ char pad112[1];
    /* 0x113 */ u8 unk113;
    /* 0x114 */ u8 unk114;
    /* 0x115 */ char pad115[1];
    /* 0x116 */ u16 flags116;
    /* 0x118 */ f32 value118;
};

struct AiConstantPool {
    f32 f00[34];
    f64 d88;
    f64 d90;
    f32 f98[48];
    f64 d158;
    f64 d160;
    f32 f168[68];
};

extern "C" {
extern const AiConstantPool lbl_27_rodata_2CF0;
void fn_27_1FAD54(AiInput* self);
void fn_27_21CDD8(int* dest, int a, int b, const char* c);
void free__13gfHeapManagerFPv(void* ptr);
}

extern "C" void fn_27_1F35E4(AiInput* self, void* arg) {
    self->unk30 = arg;
    self->value118 = lbl_27_rodata_2CF0.f00[0];
    fn_27_1FAD54(self);
    fn_27_21CDD8((int*)&self->parameters, 0, -1, 0);
    if (self->flags & 0x40) {
        if (self->scriptBuffer) {
            free__13gfHeapManagerFPv(self->scriptBuffer);
            self->scriptBuffer = 0;
        }
        self->flags = self->flags & ~0x40;
    }
}
