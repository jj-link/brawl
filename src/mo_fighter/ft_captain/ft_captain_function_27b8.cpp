#pragma force_active on
extern "C" {
void* fn_100_2158(void*, short);
void* fn_100_21F4(void*, short);
void* fn_100_2234(void*, short);
void* fn_100_2850(void*, short);
void fn_27_1A62E4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_27B8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_2158(storage + 0x9F4, destroy);
        fn_100_21F4(storage + 0x9D8, destroy);
        fn_100_2234(storage + 0x92C, destroy);
        fn_100_2850(storage + 0x494, destroy);
        if (object != 0) {
            fn_27_1A62E4(object, destroy);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
