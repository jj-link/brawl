#pragma force_active on
typedef unsigned char u8;

extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_25290(void*, int);

struct fn_27_Obj {
    int m_a;
    int m_b;
    int m_c;
    u8 m_arr[0x30 * 12];
};

extern "C" fn_27_Obj* fn_27_CE2E8(fn_27_Obj* self, int flag) {
    if (self) {
        __destroy_arr(self->m_arr, fn_27_25290, 0x30, 12);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
