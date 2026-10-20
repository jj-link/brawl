#pragma force_active on
extern "C" void* fn_116_4B64(void* object, short deleting);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_27_CD934(void*, short);
void operator delete(void*);

extern "C" void* fn_116_4ADC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_4B64(storage + 0x3C, -1);
        if (storage + 0x20 != 0) {
            if (storage + 0x20 != 0) {
                if (storage + 0x20 != 0) {
                    fn_27_1A15B8(storage + 0x20, -1);
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
