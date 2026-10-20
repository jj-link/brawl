#pragma force_active on
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_4742C(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CDDE8(void*, short);
void* fn_27_CD78C(void*, short);
void __dl__FPv(void*);

void* fn_91_3514(void* object, short deleting) {
    if (object != 0) {
        fn_27_48BE8(static_cast<unsigned char*>(object) + 0x1c4, static_cast<short>(-1));
        fn_27_4742C(static_cast<unsigned char*>(object) + 0x1b4, static_cast<short>(-1));
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x130, static_cast<short>(-1));
        fn_27_CDDE8(static_cast<unsigned char*>(object) + 0x6c, static_cast<short>(-1));
        fn_27_CD78C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
