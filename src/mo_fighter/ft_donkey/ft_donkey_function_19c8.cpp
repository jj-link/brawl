#pragma force_active on
extern "C" void* fn_92_1A68(void*, short);
extern "C" void* fn_92_1E48(void*, short);
extern "C" void* fn_92_1EE4(void*, short);
extern "C" void* fn_92_201C(void*, short);
extern "C" void fn_27_125E20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_19C8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_92_1A68(static_cast<unsigned char*>(object) + 0x124e0, memberDeleting);
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_92_1E48(members + 0x12028, memberDeleting);
        fn_92_1EE4(members + 0x11fec, memberDeleting);
        fn_92_201C(members + 0x194, memberDeleting);
        fn_27_125E20(members, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
