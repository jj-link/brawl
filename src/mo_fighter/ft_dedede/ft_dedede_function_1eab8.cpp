#pragma force_active on
extern "C" void* fn_117_20DB4(void*, short);
extern "C" void* fn_117_45DC(void*, short);
extern "C" void* fn_117_463C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_1EAB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_20DB4(members + 0xE0, memberDeleting);
        fn_117_45DC(members + 0x30, memberDeleting);
        fn_117_463C(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
