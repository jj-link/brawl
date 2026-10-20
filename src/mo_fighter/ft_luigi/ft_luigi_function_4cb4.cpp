#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_99_4D2C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_99_4CB4(void* object, short deleting) {
    if (object) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x11C, -1);
        if (object)
            fn_99_4D2C(object, 0);
        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
