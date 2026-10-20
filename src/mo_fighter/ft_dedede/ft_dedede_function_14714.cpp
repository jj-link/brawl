#pragma force_active on
extern "C" {
void* fn_117_14674(void*, short);
void* fn_117_146B4(void*, short);
void* fn_117_14600(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_117_14714(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_117_14674(members + 0xB0, memberDeleting);
        fn_117_146B4(members + 0x30, memberDeleting);
        fn_117_14600(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
