#pragma force_active on
extern "C" void fn_93_1A0C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_5924(void* object, short deleting) {
    if (object != 0) {
        fn_93_1A0C(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
