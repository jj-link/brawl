#pragma force_active on
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_113_50F0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_5078(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_113_50F0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
