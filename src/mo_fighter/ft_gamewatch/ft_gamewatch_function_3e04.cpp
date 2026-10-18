#pragma force_active on
extern "C" void fn_107_1FF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_3E04(void* object, short deleting) {
    if (object != 0) {
        fn_107_1FF4(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
