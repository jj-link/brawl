#pragma force_active on
extern "C" void fn_27_1A3634(void*, short);

extern "C" void* fn_99_44F0(void* object, short deleting) {
    if (object) {
        fn_27_1A3634(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
