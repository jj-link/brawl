#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_115_5DAC(void*, short);
void* fn_115_5E0C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_5D34(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x30, -1);
        fn_115_5DAC(storage + 0x18, -1);
        fn_115_5E0C(storage + 0x4, -1);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
