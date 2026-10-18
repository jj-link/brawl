#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_361C(void*, short);
extern "C" void* fn_101_4C74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_101_35A0(void* object, short deleting) {
    if (object != 0) {
        fn_101_361C(static_cast<unsigned char*>(object) + 0x408e8, static_cast<short>(-1));
        if (object != 0) {
            fn_101_4C74(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
