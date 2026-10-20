#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_5B54(void* object, short flag);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);

extern "C" void* fn_110_5ADC(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_110_5B54(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
