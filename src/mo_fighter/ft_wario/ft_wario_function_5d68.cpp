#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_110_41B4(void*, short);
void operator delete(void*);

extern "C" void* fn_110_5D68(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_110_41B4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
