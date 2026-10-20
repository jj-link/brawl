#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_102_4770(void*, short);

extern "C" void* fn_102_46F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x4B8, static_cast<short>(-1));
        if (object != 0) {
            fn_102_4770(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
