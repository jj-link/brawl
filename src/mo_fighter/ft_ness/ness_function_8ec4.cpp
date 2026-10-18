#pragma force_active on
extern "C" void* fn_27_1A1FE4(void*, short);
void operator delete(void*);

extern "C" void* fn_101_8EC4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A1FE4(object, static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
