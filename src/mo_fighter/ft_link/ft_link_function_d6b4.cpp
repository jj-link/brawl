#pragma force_active on
extern "C" void* fn_93_D654(void* object, short deleting);
extern "C" void* fn_93_D51C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_D6B4(void* object, short deleting) {
    if (object != 0) {
        fn_93_D654(static_cast<char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_93_D51C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
