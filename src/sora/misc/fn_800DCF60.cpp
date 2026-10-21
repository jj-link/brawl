#pragma force_active on
typedef unsigned char u8;

struct fnInner27 {
    u8 pad[0x39];
    u8 val;
};

struct fnOuter27 {
    u8 pad[0x94];
    fnInner27* inner;
};

extern "C" void fn_800DCF60(fnOuter27* self, u8 v) {
    fnInner27* p = self->inner;
    if (p != 0) {
        p->val = v;
    }
}
