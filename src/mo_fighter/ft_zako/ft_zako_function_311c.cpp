#pragma force_active on
extern "C" {
void* fn_126_31B8(void*, short);
void* fn_126_323C(void*, short);
void* fn_126_329C(void*, short);
void* fn_126_32F8(void*, short);
void* fn_126_3DB0(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_311C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_31B8(storage + 0xDB0, -1);
        fn_126_323C(storage + 0xD9C, -1);
        fn_126_329C(storage + 0x930, -1);
        fn_126_32F8(storage + 0xBC, -1);
        fn_126_3DB0(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
