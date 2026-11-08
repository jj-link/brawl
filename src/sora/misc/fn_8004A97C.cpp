#pragma force_active on
typedef unsigned char u8;

struct Inner {
    int unk0;
    u8 pad[0x45];
    u8 b49;
};

struct Outer {
    u8 pad[0x18];
    Inner* inner;
    u8 pad2[0x8];
    u8 flags;
};

extern "C" int fn_8004B8BC(void* self, unsigned int arg1, int arg2);

extern "C" int fn_8004A97C(Outer* self, int arg) {
    if (arg != 0) {
        Inner* p = self->inner;
        unsigned int r0 = 0;
        if (p != 0) {
            r0 = (unsigned int)__cntlzw(p->unk0 - 1) >> 5;
        }
        if (r0 != 0) {
            self->flags |= 0x10;
        }
        return fn_8004B8BC(self->inner, self->inner->b49, 1);
    }
    if ((self->flags >> 4) & 1) {
        self->flags &= ~0x10;
    }
    return fn_8004B8BC(self->inner, self->inner->b49, 0);
}
