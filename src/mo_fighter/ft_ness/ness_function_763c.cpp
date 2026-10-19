#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A3A44(void*, short);

extern "C" void* fn_101_763C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A3A44(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
