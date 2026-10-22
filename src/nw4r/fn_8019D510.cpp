#pragma force_active on

extern "C" void* fn_80197184(void** arg0, unsigned int arg1);
extern "C" void fn_80196530(void* arg0, float* arg1, float arg2);

struct Obj {
    unsigned char pad0[0x0C];
    float m0C;
    unsigned char pad1[0x34 - 0x10];
    char* m34;
};

extern "C" void* fn_8019D510(Obj* self, int* out, unsigned int id) {
    void* sp8;
    void* t;
    char* base;

    t = fn_80197184((void**)((char*)self + 0x20), id);
    sp8 = t;
    if (t == 0) {
        *out = 0;
        return out;
    }
    base = self->m34;
    if (base != 0) {
        return base + *(unsigned int*)((char*)t + 0xC) * 0x34;
    }
    fn_80196530(&sp8, (float*)out, self->m0C);
    return out;
}
