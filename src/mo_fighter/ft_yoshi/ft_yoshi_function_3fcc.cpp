#pragma force_active on
extern "C" {
void* fn_95_4054(void* object, short deleting);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void operator delete(void*);
}

extern "C" void* fn_95_3FCC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_4054(storage + 0x8C, -1);
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
