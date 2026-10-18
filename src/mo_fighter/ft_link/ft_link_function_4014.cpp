#pragma force_active on
extern "C" {
void* fn_27_150488(void*, short);
void* fn_93_3FB8(void*, short);
void* fn_27_199A54(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_93_4014(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_150488(members + 0x5B8, memberDeleting);
        fn_93_3FB8(members + 0x584, memberDeleting);
        if (object != 0) {
            fn_27_199A54(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
