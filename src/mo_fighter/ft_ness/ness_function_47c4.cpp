#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_3544C(void*, short);
}

extern "C" void* fn_101_47C4(void* object, short deleting) {
    if (object != 0) {
        fn_27_3544C(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
