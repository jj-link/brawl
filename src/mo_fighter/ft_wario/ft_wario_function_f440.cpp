#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_F4B0(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_110_F440(void* object, short deleting) {
    if (object != 0) {
        fn_110_F4B0(static_cast<unsigned char*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
