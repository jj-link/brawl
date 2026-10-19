#pragma force_active on
extern "C" void* fn_99_31CC(void*, short);

extern "C" void* fn_99_3170(void* object, short deleting) {
    if (object) {
        short destroyBase = -1;
        fn_99_31CC(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
