#pragma force_active on
typedef unsigned char u8;

struct Sub {
    u8 pad[0x1C];
    void (*fn)(void*, Sub*, void*);
    void* ptr;
    u8 flag;
};

struct Outer {
    u8 pad[0x3C];
    Sub* sub;
};

extern "C" void fn_8015CD80(void* a, Outer* b) {
    Sub* sub = b->sub;
    sub->flag = 0;
    if (sub->fn) {
        sub->fn(a, sub, sub->ptr);
    }
}
