#pragma force_active on
extern "C" void* fn_116_6EE0(void* object, short deleting);

void operator delete(void* p);

extern "C" void* fn_116_6E84(void* object, short deleting) {
    if (object != 0) {
        fn_116_6EE0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
