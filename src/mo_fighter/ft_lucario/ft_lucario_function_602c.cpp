#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1540CC(void*, short);

extern "C" void* fn_118_602C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
