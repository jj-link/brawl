#pragma force_active on
extern "C" void* fn_93_16E50(void*, short);
extern "C" void* fn_93_17110(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_16DE0(void* object, short deleting) {
    if (object != 0) {
        fn_93_16E50(static_cast<unsigned char*>(object) + 0x3110, -1);
        fn_93_17110(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
