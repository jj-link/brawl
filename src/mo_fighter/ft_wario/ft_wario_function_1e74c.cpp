#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_110_1E7D0(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1E74C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_93100(members + 0x2ae0, memberDeleting);
        fn_110_1E7D0(members + 0x7c, memberDeleting);
        fn_27_19F4C4(members + 0x20, memberDeleting);
        fn_27_1A55B0(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
