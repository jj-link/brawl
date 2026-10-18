#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5994(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_18C6C(void* object, short deleting) {
    if (object != 0) {
        fn_101_5994(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
