#pragma force_active on
#include <mu/mu_object.h>

extern const float lbl_28_rodata_0[];

struct AdvMenuNameState {
    char pad00[0x10C];
    int f10C[8];
};

inline void helper(AdvMenuNameState* self, u32 idx, MuObject* obj) {
    const float* ro = lbl_28_rodata_0;
    switch (self->f10C[idx]) {
    case 0:
        obj->setFrameNode(ro[0x8C / 4]);
        if (self->f10C[idx + 2] > 0) {
            obj->setFrameVisible(ro[0x90 / 4]);
            return;
        }
        if (self->f10C[4] == 0) {
            obj->setFrameVisible(ro[0x8C / 4]);
            return;
        }
        obj->setFrameVisible(ro[0x94 / 4]);
        return;
    case 1:
        obj->setFrameNode(ro[0x94 / 4]);
        if (self->f10C[4] == 1) {
            obj->setFrameVisible(ro[0x98 / 4]);
            return;
        }
        obj->setFrameVisible(ro[0x90 / 4]);
        return;
    case 2:
        obj->setFrameNode(ro[0x98 / 4]);
        if (self->f10C[4] == 2) {
            obj->setFrameVisible(ro[0x98 / 4]);
            return;
        }
        obj->setFrameVisible(ro[0x90 / 4]);
        return;
    case 3:
        obj->setFrameNode(ro[0x90 / 4]);
        if (self->f10C[4] == 3) {
            obj->setFrameVisible(ro[0x98 / 4]);
            return;
        }
        obj->setFrameVisible(ro[0x90 / 4]);
        return;
    case 4:
        obj->setFrameNode(ro[0x9C / 4]);
        if (self->f10C[idx + 2] < self->f10C[4] - 4) {
            obj->setFrameVisible(ro[0x90 / 4]);
            return;
        }
        obj->setFrameVisible(ro[0x98 / 4]);
        return;
    }
}
extern "C" void fn_28_175C(AdvMenuNameState* self, u32 idx, MuObject* obj) {
    helper(self, idx, obj);
}
