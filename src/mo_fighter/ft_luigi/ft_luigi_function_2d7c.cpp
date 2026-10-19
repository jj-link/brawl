#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);

extern "C" void* fn_99_2D7C(void* object, short deleting) {
    if (object) {
        fn_27_B64B8(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
