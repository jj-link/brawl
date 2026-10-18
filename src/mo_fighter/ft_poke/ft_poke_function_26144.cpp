#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_D2AA4(void*, short);

extern "C" void* fn_116_26144(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_D2AA4(object, static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
