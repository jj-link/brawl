#pragma force_active on
extern "C" void* fn_113_2D0C(void*, short);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_113_3F04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2D0C(storage + 0x8C, -1);
        if (storage + 0x20 != 0) {
            if (storage + 0x20 != 0) {
                if (storage + 0x20 != 0) {
                    fn_27_1A1E70(storage + 0x20, -1);
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
