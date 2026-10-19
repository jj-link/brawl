#pragma force_active on
extern "C" void* fn_99_9F94(void*, short);
extern "C" void* fn_99_9E74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_9FF4(void* object, short deleting) {
    if (object) {
        fn_99_9F94(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_99_9E74(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
