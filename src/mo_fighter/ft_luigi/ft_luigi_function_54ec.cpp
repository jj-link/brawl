#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);

extern "C" void* fn_99_54EC(void* object, short deleting) {
    if (object) {
        fn_27_64D9C(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
