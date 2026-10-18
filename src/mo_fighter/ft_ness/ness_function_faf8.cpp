#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_101_FA9C(void*, short);
void __dl__FPv(void*);

void* fn_101_FAF8(void* object, short deleting) {
    if (object != 0) {
        fn_101_FA9C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
