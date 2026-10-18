#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_3E20(void*, short);
void* fn_92_3EA4(void*, short);
void* fn_92_14B9C(void*, short);
void* fn_92_3F04(void*, short);
void* fn_92_402C(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_92_14B00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_3E20(members + 0x114, memberDeleting);
        fn_92_3EA4(members + 0x100, memberDeleting);
        fn_92_14B9C(members + 0xec, memberDeleting);
        fn_92_3F04(members + 0x48, memberDeleting);
        fn_92_402C(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
