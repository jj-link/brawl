#pragma force_active on
extern "C" void* fn_115_4118(void*, short);
extern "C" void* fn_115_4338(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_42C8(void* object, short deleting) {
    if (object != 0) {
        fn_115_4118(static_cast<unsigned char*>(object) + 0x9EB4, -1);
        fn_115_4338(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
