#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_3B0C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_101_18DC8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_101_3B0C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
