#pragma force_active on
typedef unsigned int u32;

struct S {
    char pad[0xF4];
    unsigned char flag;
    char padF5[3];
};

extern "C" void** fn_801A7550(void**, void*);

extern "C" void* fn_801AC5B0(S* __restrict self) {
    void* temp;
    void** p = &temp;
    p = fn_801A7550(p, (char*)self + (int)(self->flag * 0x10C) + 0xF8);
    return *p;
}
