#pragma force_active on
extern "C" void* fn_27_66114(void*, short);

extern "C" void* fn_99_5490(void* object, short deleting) {
    if (object) {
        fn_27_66114(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
