#include <types.h>
#pragma force_active on

extern "C" void fn_41_2360(void* self, s32 v);
extern "C" u8 lbl_41_data_DFC[];

struct emSoraEnemyObj {
    void* vtbl;
    s32 unk4;
    void* unk8;
    s32 unkC;
};

extern "C" emSoraEnemyObj* fn_41_2F430(emSoraEnemyObj* self, void* p2) {
    fn_41_2360(self, 0);
    self->vtbl = lbl_41_data_DFC;
    self->unk8 = p2;
    self->unkC = -1;
    return self;
}
