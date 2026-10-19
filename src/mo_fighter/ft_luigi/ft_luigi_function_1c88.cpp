#pragma force_active on
extern "C" void* fn_99_1A58(void*, short);

extern "C" void* fn_99_1C88(void* object, short deleting) {
    if (object) {
        fn_99_1A58(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
