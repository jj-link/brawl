#pragma force_active on
extern "C" {
void* fn_104_3F88(void*, short);
void* fn_104_400C(void*, short);
void* fn_104_23CC0(void*, short);
void* fn_104_406C(void*, short);
void* fn_104_23D1C(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_104_23C24(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_3F88(storage + 0x138, -1);
        fn_104_400C(storage + 0x124, -1);
        fn_104_23CC0(storage + 0xf4, -1);
        fn_104_406C(storage + 0x50, -1);
        fn_104_23D1C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
