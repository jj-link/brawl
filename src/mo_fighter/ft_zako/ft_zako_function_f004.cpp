#pragma force_active on
extern "C" {
void* fn_126_186C(void*, short);
void* fn_126_1C4C(void*, short);
void* fn_126_1CE8(void*, short);
void* fn_126_F09C(void*, short);
void fn_27_125E20(void*, short);
}

extern "C" void* fn_126_F004(void* object, short deleting) {
    if (object != 0) {
        fn_126_186C((char*)object + 0x8084, -1);
        fn_126_1C4C((char*)object + 0x7bcc, -1);
        fn_126_1CE8((char*)object + 0x7b90, -1);
        fn_126_F09C((char*)object + 0x194, -1);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
