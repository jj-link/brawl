#include <types.h>
#pragma force_active on

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} S_803678E0_Self;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
} Entry;

extern int fn_8035A590(int);
extern int fn_8035A598(int, int);
extern int fn_80367B44(s32, int);

s32 fn_803678E0(S_803678E0_Self* self, s32 arg1, s32* out1, s32* out2) {
    Entry* e;
    s32 i;

    if (self->unkC == -1) {
        self->unkC = self->unk8;
    }
    i = self->unkC + 1;
    while (i < fn_8035A590(self->unk0)) {
        e = (Entry*)fn_8035A598(self->unk0, i);
        if (e->unk14 == self->unk8 && fn_80367B44(arg1, (int)e) != 0) {
            self->unkC = i;
            *out1 = e->unk8;
            *out2 = e->unkC;
            return 1;
        }
        if (e->unk14 < self->unk8) {
            return 0;
        }
        i++;
    }
    return 0;
}
