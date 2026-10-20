#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3DEC(void*, short);
void fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_100_3D64(void* object, short deleting) {
    if (object != 0) {
        char* storage = (char*)object;
        short destroy = -1;
        fn_100_3DEC(storage + 0x8c, destroy);
        if ((storage + 0x20) && (storage + 0x20) && (storage + 0x20)) {
            fn_27_1A1E70(storage + 0x20, destroy);
        }
        fn_27_CD934(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
