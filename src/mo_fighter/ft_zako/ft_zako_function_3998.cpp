#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_126_3A10(void*, short);

extern "C" void* fn_126_3998(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x190, -1);
        if (object != 0) {
            fn_126_3A10(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
