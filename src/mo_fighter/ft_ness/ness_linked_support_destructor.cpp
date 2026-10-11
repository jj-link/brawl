void operator delete(void*);
extern "C" void* fn_101_1579C(void*, short);

extern "C" void* fn_101_157DC(void* object, short deleting) {
    if (object != 0) {
        fn_101_1579C(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
