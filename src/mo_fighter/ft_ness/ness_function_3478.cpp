#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_101_34D4(void*, short);
}

extern "C" void* fn_101_3478(void* object, short deleting) {
    if (object != 0) {
        fn_101_34D4(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
