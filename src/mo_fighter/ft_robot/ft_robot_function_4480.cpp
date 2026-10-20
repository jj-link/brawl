#pragma force_active on
extern "C" void fn_120_44F8(void* object, short deleting);
extern "C" void* fn_27_1A1E70(void* object, short arg);
void operator delete(void*);

extern "C" void* fn_120_4480(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x190, -1);
        if (object != 0) {
            fn_120_44F8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
