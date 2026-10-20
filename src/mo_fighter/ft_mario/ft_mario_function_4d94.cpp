#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_91_4D1C(void*, short);
void __dl__FPv(void*);

void* fn_91_4D94(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2D0, static_cast<short>(-1));
        if (object != 0) {
            fn_91_4D1C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
