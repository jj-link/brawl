#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_27_B81C4(void* object, short flag);
extern "C" void fn_111_2D1C(void* object, short flag);
extern "C" void* fn_27_198034(void* object, short flag);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_2C9C(void* self, short flag) {
    if (self != 0) {
        fn_27_B81C4((u8*)self + 0xA4, -1);
        fn_111_2D1C((u8*)self + 0x48, -1);
        if (self != 0) {
            fn_27_198034(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
