#pragma force_active on
typedef unsigned char u8;

struct Item { char pad[0x1d4]; float val; };
struct Obj {
    Item** items;
    int count;
    char pad[0x4];
    u8 unkC;
    char pad2[0x54 - 0xd];
    u8 unk54;
};
struct Self {
    Obj* a;
    Obj* b;
    u8 unk8;
    u8 unk9;
    u8 unkA;
};

extern "C" void fn_8009A8EC(Obj*, Obj*);
extern "C" void fn_8009ACA0(Obj*, Obj*);
extern float lbl_805A1C98;
extern float lbl_805A1C9C;

extern "C" void fn_8008AD64(Self* self) {
    if (self->unk8 == 0) {
        if (self->unkA == 0) {
            fn_8009A8EC(self->a, self->b);
            float lo = lbl_805A1C98;
            float hi = lbl_805A1C9C;
            for (int i = 0; i < self->b->count; i++) {
                self->b->items[i]->val = lo +
                    ((float)i * (hi - lo)) / (float)self->b->count;
            }
        } else {
            fn_8009ACA0(self->a, self->b);
        }
        self->b->unk54 = 1;
    } else if (self->unkA == 0) {
        fn_8009A8EC(self->b, self->a);
    } else {
        fn_8009ACA0(self->b, self->a);
    }
    self->unk8 ^= 1;
    self->a->unkC = 0;
    self->b->unkC = 0;
}
