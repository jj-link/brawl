#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1966BC(void*, short);

extern "C" void* fn_120_2C70(void* object, short deleting) {
    if (object != 0) {
        fn_27_1966BC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
