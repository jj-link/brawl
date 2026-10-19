#pragma force_active on
extern "C" void fn_93_1A68(void*, short);
extern "C" void* fn_93_5924(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_58B8(void* object, short deleting) {
    if (object != 0) {
        fn_93_1A68(static_cast<unsigned char*>(object) + 0x20, 0);
        fn_93_5924(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
