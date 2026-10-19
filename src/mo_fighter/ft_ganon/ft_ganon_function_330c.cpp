#pragma force_active on
extern "C" void* fn_109_337C(void*, short);
extern "C" void* fn_109_45A4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_330C(void* object, short deleting) {
    if (object != 0) {
        fn_109_337C(static_cast<unsigned char*>(object) + 0x16D8, -1);
        fn_109_45A4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
