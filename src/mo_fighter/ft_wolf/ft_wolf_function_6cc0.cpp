#pragma force_active on
extern "C" void fn_125_6D38(void* object, short flag);
extern "C" void* fn_27_1A15B8(void* object, short flag);
void operator delete(void*);

extern "C" void* fn_125_6CC0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x138, -1);
        if (object != 0) {
            fn_125_6D38(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
