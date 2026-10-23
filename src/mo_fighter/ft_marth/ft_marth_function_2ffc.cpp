#pragma force_active on
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_106_3094(void*, short);
void* fn_106_30F0(void*, short);
void* fn_27_CBF58(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_106_2FFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_97968(members + 0x6C, memberDeleting);
        fn_27_1CCCC(members + 0x5C, memberDeleting);
        fn_106_3094(members + 0x50, memberDeleting);
        fn_106_30F0(members + 0x38, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
