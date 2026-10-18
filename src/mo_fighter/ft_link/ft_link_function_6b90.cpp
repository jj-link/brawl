#pragma force_active on
extern "C" void fn_93_6B30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_6B90(void* object, short deleting) {
    if (object != 0) {
        fn_93_6B30(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
