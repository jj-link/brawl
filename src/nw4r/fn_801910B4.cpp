#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad;
    u8 val;
};

extern "C" void fn_801910B4(Inner** self, u8 v) {
    Inner* p = *self;
    if (p != 0) {
        p->val = v;
    }
}
