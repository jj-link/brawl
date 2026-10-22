#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct PFCritical {
    s32 unk0;
    s32 count;
    s32 unk8;
    u32 unkC;
} PFCritical;

extern int fn_803EC3D4(int);
extern void fn_803EC27C(u32 *);

void PF_enterCritical(PFCritical *self) {
    u32 sp8;

    if (self->count == 0) {
        fn_803EC3D4(self->unk8);
        fn_803EC27C(&self->unkC);
    } else {
        fn_803EC27C(&sp8);
        if (self->unkC != sp8) {
            fn_803EC3D4(self->unk8);
            self->unkC = sp8;
        }
    }
    self->count = self->count + 1;
}
