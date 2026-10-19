#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_101_186C8(void*, short);
}

extern "C" void* fn_101_1866C(void* object, short deleting) {
    if (object != 0) {
        fn_101_186C8(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
