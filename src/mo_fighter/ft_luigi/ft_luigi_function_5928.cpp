#pragma force_active on
extern "C" void* fn_99_4034(void*, short);

extern "C" void* fn_99_5928(void* object, short deleting) {
    if (object) {
        fn_99_4034(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
