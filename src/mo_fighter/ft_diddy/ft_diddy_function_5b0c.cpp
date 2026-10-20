#pragma force_active on
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_47CCC(void*, short);
void* fn_27_CB800(void*, short);
void* fn_27_19FB24(void*, short);
void* fn_27_19E5E0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_5B0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_48BE8(p + 0xA14, -1);
        fn_27_47CCC(p + 0xA04, -1);
        fn_27_CB800(p + 0x908, -1);
        fn_27_19FB24(p + 0x78C, -1);
        fn_27_19E5E0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
