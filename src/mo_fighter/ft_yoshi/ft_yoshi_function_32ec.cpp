#pragma force_active on

extern "C" {
void* fn_27_93100(void*, short);
void* fn_95_3374(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_32EC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_93100(storage + 0x19E20, destroy);
        fn_95_3374(storage + 0x7C, destroy);
        fn_27_19F4C4(storage + 0x20, destroy);
        fn_27_1A55B0(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
