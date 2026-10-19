#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void* fn_27_5B39C(void*, short);

extern "C" void* fn_107_77D0(void* object, short deleting) {
    if (object != 0) {
        fn_27_5B39C(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
