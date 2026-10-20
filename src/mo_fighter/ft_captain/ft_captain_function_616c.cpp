#pragma force_active on
extern "C" {
void fn_27_48BE8(void*, short);
void fn_27_47CCC(void*, short);
void fn_27_CB800(void*, short);
void fn_27_19FB24(void*, short);
void fn_27_19E5E0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_616C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_48BE8(storage + 0xA14, destroy);
        fn_27_47CCC(storage + 0xA04, destroy);
        fn_27_CB800(storage + 0x908, destroy);
        fn_27_19FB24(storage + 0x78C, destroy);
        fn_27_19E5E0(object, destroy);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
