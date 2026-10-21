#pragma force_active on
typedef void (*FnPtr)(void*, void*, void*);

struct Inner {
    unsigned char pad0[8];
    void* a8;
    FnPtr fn;
    void* c10;
    unsigned char pad1[0x6c - 0x14];
    unsigned char flag6c;
};

struct Outer {
    unsigned char pad0[0x3c];
    Inner* inner;
};

extern "C" void fn_8015CD54(void* a, Outer* r4) {
    Inner* m = r4->inner;
    m->flag6c = 0;
    m->a8 = a;
    if (m->fn == 0) {
        return;
    }
    m->fn(a, m, m->c10);
}
