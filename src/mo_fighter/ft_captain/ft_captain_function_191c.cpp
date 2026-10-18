#pragma force_active on
extern "C" {
void* fn_100_19BC(void*, short);
void* fn_100_1D9C(void*, short);
void* fn_100_1E38(void*, short);
void* fn_100_1F70(void*, short);
void* fn_27_125E20(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_191C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_19BC(storage + 0xC50C, destroy);
        fn_100_1D9C(storage + 0xC054, destroy);
        fn_100_1E38(storage + 0xC018, destroy);
        fn_100_1F70(storage + 0x194, destroy);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
