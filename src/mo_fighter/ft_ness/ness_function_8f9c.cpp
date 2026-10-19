#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_CC7EC(void*, short);
}

extern "C" void* fn_101_8F9C(void* object, short deleting) {
    if (object != 0) {
        fn_27_CC7EC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
