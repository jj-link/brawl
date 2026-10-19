#pragma force_active on
extern "C" void fn_27_1A5DD0(void*, short);

extern "C" void* fn_99_27D8(void* object, short deleting) {
    if (object) {
        fn_27_1A5DD0(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
