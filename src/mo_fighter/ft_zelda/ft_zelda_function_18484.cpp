#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_40F4(void*, short);
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_18484(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_40F4(storage + 0x4C, -1);
        if (storage + 0x20 != 0) {
            if (storage + 0x20 != 0) {
                if (storage + 0x20 != 0) {
                    fn_27_1A1B88(storage + 0x20, -1);
                }
            }
        }
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
