#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3C80(void*, short);
void* fn_100_3D04(void*, short);
void* fn_100_12BC0(void*, short);
void* fn_100_3D64(void*, short);
void* fn_100_3E8C(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_100_12B24(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3C80(storage + 0x11c, destroy);
        fn_100_3D04(storage + 0x108, destroy);
        fn_100_12BC0(storage + 0xec, destroy);
        fn_100_3D64(storage + 0x48, destroy);
        fn_100_3E8C(storage + 0x10, destroy);
        fn_27_C74E8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
