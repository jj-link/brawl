#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_40F4(void*, short);
extern "C" void* fn_104_74B0(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_104_7438(void* object, short deleting) {
    if (object != 0) {
        fn_104_40F4(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_104_74B0(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
