#pragma force_active on
extern "C" {
void* fn_115_2190(void*, short);
void* fn_115_222C(void*, short);
void* fn_115_226C(void*, short);
void* fn_115_2888(void*, short);
void* fn_27_1A68FC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_27F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_2190(members + 0xA5C, memberDeleting);
        fn_115_222C(members + 0xA40, memberDeleting);
        fn_115_226C(members + 0x994, memberDeleting);
        fn_115_2888(members + 0x4C8, memberDeleting);
        if (object != 0) {
            fn_27_1A68FC(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
