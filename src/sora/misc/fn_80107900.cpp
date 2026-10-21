#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad[0x39];
    u8 val;
};

struct Outer {
    u8 pad[0x6c];
    Inner* ptr;
};

extern "C" void fn_80107900(Outer* self, u8 v) {
    Inner* p = self->ptr;
    if (p != 0) {
        p->val = v;
    }
}
