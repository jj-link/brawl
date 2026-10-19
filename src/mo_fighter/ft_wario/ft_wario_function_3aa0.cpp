#pragma force_active on

extern "C" {
void* fn_110_2344(void*, short);
void* fn_110_2268(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_110_3AA0(void* object, short deleting) {
    if (object != 0) {
        fn_110_2344(static_cast<unsigned char*>(object) + 0x50, -1);
        fn_110_2268(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
