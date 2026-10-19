#pragma force_active on
extern "C" void* fn_27_ACC5C(void*, short);

extern "C" void* fn_99_2DD8(void* object, short deleting) {
    if (object) {
        fn_27_ACC5C(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
