#pragma force_active on
extern "C" {
void fn_27_31F178(void* self, int v);
void fn_27_352B04(void* self, int v);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_352A88(void* self, int flag) {
    if (self) {
        if ((unsigned int)self + 0xcc) {
            fn_27_31F178((char*)self + 0x17a4, -1);
            fn_27_352B04((char*)self + 0xcc, 0);
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
