#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_64D9C(void*, short);

extern "C" void* fn_101_8638(void* object, short deleting) {
    if (object != 0) {
        fn_27_64D9C(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
