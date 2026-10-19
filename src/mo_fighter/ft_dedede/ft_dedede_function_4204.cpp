#pragma force_active on
extern "C" void* fn_117_3B84(void*, short);
extern "C" void* fn_117_4270(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_4204(void* object, short deleting) {
    if (object != 0) {
        fn_117_3B84(static_cast<unsigned char*>(object) + 0x7760, -1);
        fn_117_4270(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
