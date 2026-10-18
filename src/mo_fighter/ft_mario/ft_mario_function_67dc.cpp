#pragma force_active on
extern "C" {
void* fn_27_565F0(void*, short);
void __dl__FPv(void*);

void* fn_91_67DC(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0xC, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
