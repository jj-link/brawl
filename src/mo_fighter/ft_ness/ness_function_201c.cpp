#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_2078(void*, short);
}

extern "C" void* fn_101_201C(void* object, short deleting) {
    if (object != 0) {
        fn_101_2078(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
