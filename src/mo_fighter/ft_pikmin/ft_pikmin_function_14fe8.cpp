#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_1A172C(void*, short);

extern "C" void* fn_113_14FE8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A172C(object, static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
