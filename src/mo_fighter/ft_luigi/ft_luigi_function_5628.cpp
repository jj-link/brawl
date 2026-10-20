#pragma force_active on
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_47CCC(void*, short);
void* fn_27_19958C(void*, short);
void* fn_27_19FCBC(void*, short);
void* fn_27_19D830(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_99_5628(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_48BE8(storage + 0x844, -1);
        fn_27_47CCC(storage + 0x834, -1);
        fn_27_19958C(storage + 0x6C0, -1);
        fn_27_19FCBC(storage + 0x48C, -1);
        fn_27_19D830(object, -1);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
