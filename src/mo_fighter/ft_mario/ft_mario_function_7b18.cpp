#pragma force_active on
extern "C" {
void* fn_91_7AB8(void*, short);
void* fn_91_79BC(void*, short);
void __dl__FPv(void*);

void* fn_91_7B18(void* object, short deleting) {
    if (object != 0) {
        fn_91_7AB8(static_cast<unsigned char*>(object) + 0x7d38, static_cast<short>(-1));
        fn_91_79BC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
