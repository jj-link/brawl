#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_48568(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CDDE8(void*, short);
void* fn_27_CD78C(void*, short);
}

extern "C" void* fn_101_8774(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_48BE8(storage + 0x1C4, -1);
        fn_27_48568(storage + 0x1B4, -1);
        fn_27_4CAA0(storage + 0x130, -1);
        fn_27_CDDE8(storage + 0x6C, -1);
        fn_27_CD78C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
