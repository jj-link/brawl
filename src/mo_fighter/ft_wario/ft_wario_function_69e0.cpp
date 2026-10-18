#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1FE4(void*, short);

extern "C" void* fn_110_69E0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A1FE4(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
