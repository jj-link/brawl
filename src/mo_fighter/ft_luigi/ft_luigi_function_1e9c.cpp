#pragma force_active on
extern "C" void* fn_27_1362C(void*, short);

extern "C" void* fn_99_1E9C(void* object, short deleting) {
    if (object) {
        fn_27_1362C(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
