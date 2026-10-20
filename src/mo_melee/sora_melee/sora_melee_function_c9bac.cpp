#pragma force_active on
extern "C" void fn_27_7D898(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

struct fn_27_Obj {
    unsigned char m_pad[0xC];
    unsigned char m_arr[0x1C * 2];
};

extern "C" void* fn_27_C9BAC(fn_27_Obj* self, int del) {
    if (self) {
        __destroy_arr(self->m_arr, fn_27_7D898, 0x1C, 2);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
