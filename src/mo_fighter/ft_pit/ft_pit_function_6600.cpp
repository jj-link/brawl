#pragma force_active on
extern "C" void fn_112_383C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_6600(void* object, short deleting) {
    if (object != 0) {
        fn_112_383C(static_cast<unsigned char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
