#pragma force_active on

extern "C" {
void* fn_126_1F74(void*, short);
void* fn_126_2138(void*, short);
void* fn_126_2200(void*, short);
void* fn_126_228C(void*, short);
void* fn_126_2318(void*, short);
void* fn_126_23A4(void*, short);
void* fn_126_2430(void*, short);
void* fn_126_24BC(void*, short);
void* fn_126_2548(void*, short);
void* fn_126_25D4(void*, short);
void* fn_126_2660(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_1E9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_1F74(storage + 0x1478, -1);
        fn_126_2138(storage + 0x1354, -1);
        fn_126_2200(storage + 0x1228, -1);
        fn_126_228C(storage + 0x10FC, -1);
        fn_126_2318(storage + 0xFD0, -1);
        fn_126_23A4(storage + 0xEA4, -1);
        fn_126_2430(storage + 0xD78, -1);
        fn_126_24BC(storage + 0xC4C, -1);
        fn_126_2548(storage + 0xB20, -1);
        fn_126_25D4(storage + 0x9F4, -1);
        fn_126_2660(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
