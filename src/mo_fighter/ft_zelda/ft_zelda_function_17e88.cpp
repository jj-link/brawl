#pragma force_active on
extern "C" {
void* fn_104_17EF8(void*, short);
void* fn_104_1856C(void*, short);
void __dl__FPv(void*);

void* fn_104_17E88(void* object, short deleting) {
    if (object != 0) {
        fn_104_17EF8(static_cast<unsigned char*>(object) + 0xC2F0, static_cast<short>(-1));
        fn_104_1856C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
