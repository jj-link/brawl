#pragma force_active on
extern "C" void* fn_99_1A58(void*, short);

extern "C" void* fn_99_1C2C(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        fn_99_1A58(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
