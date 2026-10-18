#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_4DBC(unsigned char*, short);
void __dl__FPv(void*);
}
extern "C" void* fn_101_4D5C(void* object, short deleting) {
    if (object != 0) {
        fn_101_4DBC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}