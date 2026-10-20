#pragma force_active on
extern "C" void* fn_115_3BAC(void*, short);
extern "C" void* fn_115_4AA8(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_4A30(void* object, short deleting) {
    if (object != 0) {
        fn_115_3BAC(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_115_4AA8(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
