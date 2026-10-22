#include <types.h>
#pragma force_active on

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} S_8036784C_Self;

extern s32 fn_8035A590(s32);
extern s32 fn_8035A598(s32, s32);
extern s32 fn_80367B44(s32, s32);

s32 fn_8036784C(S_8036784C_Self* self, s32 arg1) {
    s32 i;

    i = self->unk8 + 1;
    while (i < fn_8035A590(self->unk0)) {
        if (fn_80367B44(arg1, fn_8035A598(self->unk0, i)) != 0) {
            self->unk8 = i;
            self->unkC = -1;
            return 1;
        }
        i++;
    }
    return 0;
}
