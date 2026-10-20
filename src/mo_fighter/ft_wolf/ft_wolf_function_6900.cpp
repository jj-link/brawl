#pragma force_active on
void operator delete(void*);
extern "C" void fn_125_6978(void* object, short deleting);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);

extern "C" void* fn_125_6900(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x318, -1);
        if (object != 0) {
            fn_125_6978(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
