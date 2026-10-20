#pragma force_active on
extern "C" void fn_27_25290(void* ptr, int count);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

struct fn_27_Obj {
    unsigned char m_pad[0xC];
};

extern "C" void* fn_27_CEE10(fn_27_Obj* self, int flags) {
    if (self) {
        __destroy_arr((unsigned char*)self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0x17);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
