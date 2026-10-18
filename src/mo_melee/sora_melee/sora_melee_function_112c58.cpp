#pragma force_active on
struct Inner {
    unsigned char pad[0x60];
    void* f60;
};

struct Outer {
    Inner* inner;
    unsigned char pad[6];
    unsigned char flag;
};

extern "C" void fn_27_112C58(Outer* p, void* v) {
    if (p->flag != 1) {
        return;
    }
    p->inner->f60 = v;
}
