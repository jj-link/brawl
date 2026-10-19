#pragma force_active on
extern "C" void* fn_27_1540CC(void*, short);
void operator delete(void*);

extern "C" void* fn_119_49DC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1540CC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
