#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[2];
    u8 val;
};

struct Outer {
    Inner* ptr;
};

extern "C" void fn_801910C8(Outer* self, u8 val) {
    Inner* p = self->ptr;
    if (p != 0) {
        p->val = val;
    }
}
