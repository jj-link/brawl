#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3C80(void*, short);
void* fn_100_3D04(void*, short);
void* fn_100_5034(void*, short);
void* fn_100_5090(void*, short);
void* fn_100_5AA8(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_100_4F98(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3C80(storage + 0xdd8, destroy);
        fn_100_3D04(storage + 0xdc4, destroy);
        fn_100_5034(storage + 0x930, destroy);
        fn_100_5090(storage + 0xbc, destroy);
        fn_100_5AA8(storage + 0x10, destroy);
        fn_27_C74E8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
