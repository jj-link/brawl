#pragma force_active on
extern "C" {
void fn_27_48BE8(void*, short);
void fn_27_4742C(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_CDDE8(void*, short);
void fn_27_CD78C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_68B0(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        char* storage = static_cast<char*>(object);
        fn_27_48BE8(storage + 0x1C4, destroy);
        fn_27_4742C(storage + 0x1B4, destroy);
        fn_27_4CAA0(storage + 0x130, destroy);
        fn_27_CDDE8(storage + 0x6C, destroy);
        fn_27_CD78C(object, destroy);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
