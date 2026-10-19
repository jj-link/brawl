#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);

extern "C" void* fn_99_2C44(void* object, short deleting) {
    if (object) {
        fn_27_BED74(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
