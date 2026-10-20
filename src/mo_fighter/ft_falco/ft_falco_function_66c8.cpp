#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_108_6740(void*, short);

extern "C" void* fn_108_66C8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x4B8, static_cast<short>(-1));
        if (object != 0) {
            fn_108_6740(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
