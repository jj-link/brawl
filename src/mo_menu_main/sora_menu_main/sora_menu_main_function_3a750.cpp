#include <types.h>
#pragma force_active on
extern "C" void fn_2_3B850(void*, s32, s32);
extern "C" u8 lbl_2_data_4D38[0x140];
struct Table { s32 v[12]; };
extern "C" Table lbl_2_rodata_1780;
struct Self {
    char pad0[0x1B0]; s32 unk1B0; char pad1[0xC];
    s32 unk1C0; s32 unk1C4; s32 list[17]; s32 unk20C;
};
static bool isFlagged(u32 idx) {
    return (lbl_2_data_4D38[idx * 0x14 + 0x10] >> 7) & 1;
}
static void push(Self* self, u32 a) {
    self->list[self->unk1C4++] = a;
}
extern "C" void fn_2_3A750(Self* self) {
    Table t = lbl_2_rodata_1780;
    self->unk1C4 = 0;
    for (s32 i = 0; i < 12; i++) {
        u32 a = t.v[i];
        if (isFlagged(a)) push(self, a);
    }
    s32* q;
    s32 target = self->unk20C;
    s32 count = 0;
    if (target != -1) {
        q = t.v;
        while (target != *q) {
            if (isFlagged(*q)) count++;
            q++;
        }
    }
    self->unk1B0 = -1;
    self->unk1C0 = -1;
    fn_2_3B850(self, count % 6, count / 6);
}