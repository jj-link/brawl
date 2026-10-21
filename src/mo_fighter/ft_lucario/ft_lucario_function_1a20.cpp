#pragma force_active on
extern "C" {
void* fn_118_1AD8(void*, short);
void* fn_118_1B98(void*, short);
void* fn_118_1BF4(void*, short);
void* fn_118_1C50(void*, short);
void* fn_118_1CAC(void*, short);
void* fn_118_1D08(void*, short);
void* fn_118_1D64(void*, short);
void* fn_118_1DC0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_118_1A20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_118_1AD8(members + 0x84, memberDeleting);
        fn_118_1B98(members + 0x70, memberDeleting);
        fn_118_1BF4(members + 0x5C, memberDeleting);
        fn_118_1C50(members + 0x48, memberDeleting);
        fn_118_1CAC(members + 0x34, memberDeleting);
        fn_118_1D08(members + 0x20, memberDeleting);
        fn_118_1D64(members + 0x8, memberDeleting);
        fn_118_1DC0(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
