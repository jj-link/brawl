#pragma force_active on
extern "C" void* fn_115_3AC8(void*, short);
extern "C" void* fn_115_3B4C(void*, short);
extern "C" void* fn_115_15EB0(void*, short);
extern "C" void* fn_115_15E38(void*, short);
extern "C" void* fn_115_15D1C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_15F0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3AC8(storage + 0x12c, -1);
        fn_115_3B4C(storage + 0x118, -1);
        fn_115_15EB0(storage + 0x100, -1);
        fn_115_15E38(storage + 0x5c, -1);
        fn_115_15D1C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
