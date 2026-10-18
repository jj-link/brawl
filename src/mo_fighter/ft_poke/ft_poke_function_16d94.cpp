#pragma force_active on
extern "C" {
void fn_116_3CA4(void*, short);
void fn_116_3D28(void*, short);
void fn_116_16E30(void*, short);
void fn_116_5744(void*, short);
void fn_116_615C(void*, short);
void fn_27_C74E8(void*, short);
}

extern "C" void* fn_116_16D94(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_3CA4(storage + 0xdcc, -1);
        fn_116_3D28(storage + 0xdb8, -1);
        fn_116_16E30(storage + 0x930, -1);
        fn_116_5744(storage + 0xbc, -1);
        fn_116_615C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
