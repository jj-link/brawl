#pragma force_active on
extern "C" void* fn_27_1540CC(void*, short);

extern "C" void* fn_99_5434(void* object, short deleting) {
    if (object) {
        fn_27_1540CC(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
