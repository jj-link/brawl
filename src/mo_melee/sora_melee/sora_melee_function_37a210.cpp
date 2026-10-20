#pragma force_active on
extern "C" void fn_27_37A2D0(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37A210(void* self, int flags) {
    if (self) {
        if ((char*)self + 8 != 0) {
            fn_27_37A2D0((char*)self + 0xc, -1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
