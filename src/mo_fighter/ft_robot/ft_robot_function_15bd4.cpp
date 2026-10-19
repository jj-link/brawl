#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_15B64(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_120_15BD4(void* object, short deleting) {
    if (object != 0) {
        fn_120_15B64(static_cast<unsigned char*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
