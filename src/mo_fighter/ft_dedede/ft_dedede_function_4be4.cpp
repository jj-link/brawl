#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_117_4C5C(void*, short);
void operator delete(void*);

extern "C" void* fn_117_4BE4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, static_cast<short>(-1));
        if (object != 0) {
            fn_117_4C5C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
