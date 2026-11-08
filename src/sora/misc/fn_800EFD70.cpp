#include <mu/mu_object.h>
#pragma force_active on
struct State {
    MuObject* objects[18];
    unsigned char pad[12];
    int field54;
    int field58;
    unsigned char pad5c[12];
    int field68;
    int field6c;
};
extern "C" void fn_800EFC08(State*);
extern "C" void fn_800EFE58(State*, int, const void*, int);
extern "C" void fn_800EFF2C(State*);
extern int lbl_805A2590;
extern int lbl_80408B98[10];
extern int lbl_80408BC0[10];
extern float lbl_805A2598;
extern "C" void fn_800EFD70(State* self, int a, int* b, int c, int* d, int flags) {
    fn_800EFC08(self);
    self->field54 = *b;
    self->field58 = c;
    self->field68 = *d;
    fn_800EFE58(self, a, &lbl_805A2590, 1);
    self->field6c = flags;
    if (flags & 3) {
        fn_800EFE58(self, a, lbl_80408B98, 5);
        if (flags & 2) {
            MuObject** p = &self->objects[1];
            for (int i = 1; i < 6; i++) {
                p[1]->setFrameVisible(lbl_805A2598);
                p++;
            }
        }
    }
    if (flags & 4) {
        fn_800EFE58(self, a, lbl_80408BC0, 5);
    }
    fn_800EFF2C(self);
}