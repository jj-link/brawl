#pragma force_active on
extern "C" void fn_27_37A2D0(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37A274(void* self, int flag) {
    if (self) {
        fn_27_37A2D0((char*)self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
