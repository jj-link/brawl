#pragma force_active on
extern "C" {
void* fn_91_2CFC(void* object, short deleting);
void* __dl__FPv(void*);

void* fn_91_2D5C(void* object, short deleting) {
    if (object != 0) {
        fn_91_2CFC(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
