#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_119_40B4(void*, short);

extern "C" void* fn_119_403C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x190, static_cast<short>(-1));
        if (object != 0) {
            fn_119_40B4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
