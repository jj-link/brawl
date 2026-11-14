#include <types.h>
#include <mt/mt_vector.h>
#include <mu/mu_object.h>
#pragma force_active on
struct SelChar {
    s32 field0; s32 field4; MuObject* field8;
    char pad0C[0x24]; MuObject* field30; MuObject* field34;
    char pad38[0xC]; s32 field44; char pad48[0x24];
    s32 field6C; u16 ids[0x40]; char pad0F0[0x70]; s32 field160;
};
typedef s32 (*SelCmp)(const void*, const void*);
extern "C" {
extern s32 g_GameGlobal;
extern const float lbl_10_rodata_8A8[];
s32 fn_8004D148(s32);
void fn_800B6838(MuObject*, const Vec3f*);
s32 fn_10_1CCE8(const void*, const void*);
void fn_803F8ACC(u16*, u32, u32, SelCmp);
void fn_10_1CF64(SelChar*, s32);
inline void fillIds(SelChar* self, int count) {
    for (int i = 0; i < count; ++i) self->ids[i] = i;
}
inline int findId(SelChar* self, int index) {
    for (int i = 0; i < self->field6C; ++i) {
        if (index == self->ids[i]) return i;
    }
    return -1;
}
void fn_10_1C97C(SelChar* self, s32 mode, s32 index, const Vec3f* pos) {
    const float* base = lbl_10_rodata_8A8;
    s32 limit;
    s32 j;
    s32 k;
    s32 found;
    s32 sw;
    f32 frame;
    self->field0 = mode;
    fn_800B6838(self->field8, pos);
    if (mode == 0) {
        limit = fn_8004D148(g_GameGlobal);
        fillIds(self, limit);
        if (limit > 1) fn_803F8ACC(self->ids, limit, 2, fn_10_1CCE8);
        self->field6C = limit;
    } else {
        self->field6C = 0;
    }
    switch (self->field0) {
    case 0: limit = self->field6C + 1; break;
    case 1: limit = 9; break;
    case 2: limit = 0x1F; break;
    case 3: limit = 0x1F; break;
    }
    if (mode == 0) {
        if (index == 0x78) {
            index = 0;
        } else {
            found = findId(self, index);
            index = found + 1;
        }
        if (index < 0 || index >= limit) {
            self->field44 = -1;
        } else {
            self->field44 = index;
        }
    } else {
        if (index < 0) {
            self->field44 = 0;
        } else if (index >= limit) {
            self->field44 = limit - 1;
        } else {
            self->field44 = index;
        }
    }
    self->field4 = 1;
    if (mode == 0) {
        frame = base[9];
        self->field30->setFrameVisible(frame);
        self->field34->setFrameVisible(frame);
    }
    self->field160 = 0;
    fn_10_1CF64(self, self->field44);
    s32 type = self->field0;
    s32 selected = self->field44;
    s32 a = selected > -(type == 0);
    switch (type) {
    case 0: sw = self->field6C + 1; break;
    case 1: sw = 9; break;
    case 2: sw = 0x1F; break;
    case 3: sw = 0x1F; break;
    }
    if (type == 0) sw++;
    {
        s32 b = selected < (sw - 1);
        if (a) frame = b ? base[10] : base[11];
        else frame = b ? base[12] : base[9];
    }
    self->field8->setFrameVisible(frame);
}
}