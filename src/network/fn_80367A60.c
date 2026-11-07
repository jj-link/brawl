#include <types.h>
#include <stdlib.h>
#pragma force_active on

typedef struct { int unk0, unk4, unk8, unkC; } Self;
typedef struct { int unk0, unk4; char *unk8; int unkC, unk10, unk14; } Entry;
extern int fn_8035A590(int);
extern int fn_8035A598(int, int);
extern int fn_80367B44(int, int);

int fn_80367A60(Self *self, int arg1, int *out) {
    Entry *e;
    int i;
    if (self->unkC == -1) self->unkC = self->unk8;
    i = self->unkC + 1;
    while (i < fn_8035A590(self->unk0)) {
        e = (Entry *)fn_8035A598(self->unk0, i);
        if (e->unk14 == self->unk8 && fn_80367B44(arg1, (int)e) != 0) {
            self->unkC = i;
            if (e->unk8 == 0) return 0;
            *out = atoi(e->unk8);
            return 1;
        }
        if (e->unk14 < self->unk8) return 0;
        i++;
    }
    return 0;
}