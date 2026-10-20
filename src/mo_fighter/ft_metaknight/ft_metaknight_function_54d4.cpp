#pragma force_active on
typedef unsigned char u8;
typedef short s16;

extern "C" void fn_27_48BE8(void*, s16);
extern "C" void fn_27_4742C(void*, s16);
extern "C" void fn_27_4CAA0(void*, s16);
extern "C" void fn_27_CDDE8(void*, s16);
extern "C" void fn_27_CD78C(void*, s16);

extern "C" void* fn_111_54D4(void* self, s16 flag) {
    s16 destroy = -1;
    if (self != 0) {
        fn_27_48BE8((u8*)self + 0x1C4, destroy);
        fn_27_4742C((u8*)self + 0x1B4, destroy);
        fn_27_4CAA0((u8*)self + 0x130, destroy);
        fn_27_CDDE8((u8*)self + 0x6C, destroy);
        fn_27_CD78C(self, destroy);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
