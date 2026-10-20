#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_114_837C(void* object, short deleting);
extern "C" void* fn_114_83DC(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_8304(void* object, short deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_114_837C(static_cast<unsigned char*>(object) + 0x18, -1);
        fn_114_83DC(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
