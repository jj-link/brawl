#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void fn_110_5ADC(void* object, short flag);
}

extern "C" void* fn_110_5A64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0xf0, -1);
        if (object != 0) {
            fn_110_5ADC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
