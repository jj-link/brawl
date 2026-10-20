#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_101_3478(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);

extern "C" void* fn_101_33F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x429D0, static_cast<short>(-1));
        fn_101_3478(storage + 0x7C, static_cast<short>(-1));
        fn_27_19F4C4(storage + 0x20, static_cast<short>(-1));
        fn_27_1A55B0(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
