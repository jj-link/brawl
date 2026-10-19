#pragma force_active on
typedef signed short s16;

extern "C" void* fn_27_565F0(void*, s16);
extern "C" void* fn_111_5140(void* object, s16 deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_50D4(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_111_5140(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
