#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1FE4(void* object, short value);
extern "C" void fn_110_5794(void* object, short deleting);

extern "C" void* fn_110_571C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<unsigned char*>(object) + 0x244, -1);
        if (object != 0) {
            fn_110_5794(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
