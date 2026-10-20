#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_110_571C(void* object, short deleteFlag);

extern "C" void* fn_110_56A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* bytes = static_cast<unsigned char*>(object);
        fn_27_1A1B88(bytes + 0x2D0, -1);
        if (object != 0) {
            fn_110_571C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
