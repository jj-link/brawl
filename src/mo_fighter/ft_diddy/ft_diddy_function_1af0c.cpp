#pragma force_active on
extern "C" {
void* fn_115_1AE6C(void*, short);
void* fn_115_1AEAC(void*, short);
void* fn_115_1ADF8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_1AF0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_1AE6C(storage + 0xB0, -1);
        fn_115_1AEAC(storage + 0x30, -1);
        fn_115_1ADF8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
