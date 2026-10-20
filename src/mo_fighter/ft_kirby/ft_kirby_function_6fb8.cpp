#pragma force_active on
extern "C" void* fn_96_330C(void* object, short deleting);
extern "C" void* fn_27_D2AA4(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_96_6FB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_330C(storage + 0x6C, -1);
        if (storage + 0x20 != 0) {
            if (storage + 0x20 != 0) {
                if (storage + 0x20 != 0) {
                    fn_27_D2AA4(storage + 0x20, -1);
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
