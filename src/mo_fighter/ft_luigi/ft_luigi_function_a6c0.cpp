#pragma force_active on
extern "C" void* fn_99_3C2C(void*, short);

extern "C" void* fn_99_A6C0(void* object, short deleting) {
    if (object) {
        fn_99_3C2C(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
