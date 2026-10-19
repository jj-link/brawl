#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A405C(void*, short);
}

extern "C" void* fn_101_6D94(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A405C(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
