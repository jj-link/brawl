#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_96_52C0(void*, short);

extern "C" void* fn_96_5338(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x190, static_cast<short>(-1));
        if (object != 0) {
            fn_96_52C0(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
