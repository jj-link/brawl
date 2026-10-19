#pragma force_active on
extern "C" void fn_27_7700(void*, short);

extern "C" void* fn_99_1E40(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_27_7700(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
