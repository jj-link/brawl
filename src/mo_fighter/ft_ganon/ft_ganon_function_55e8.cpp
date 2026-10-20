#pragma force_active on
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_109_5660(void* object, short flag);
extern void operator delete(void*);

extern "C" void* fn_109_55E8(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xb4, -1);
        if (object != 0) {
            fn_109_5660(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
