#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_3AC8(void*, short);
extern "C" void* fn_115_3B4C(void*, short);
extern "C" void* fn_115_1AD00(void*, short);
extern "C" void* fn_115_15E38(void*, short);
extern "C" void* fn_115_1ACA0(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1AD5C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3AC8(storage + 0x108, -1);
        fn_115_3B4C(storage + 0xf4, -1);
        fn_115_1AD00(storage + 0xe4, -1);
        fn_115_15E38(storage + 0x40, -1);
        fn_115_1ACA0(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
