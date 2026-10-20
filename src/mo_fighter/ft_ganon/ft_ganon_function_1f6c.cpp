#pragma force_active on
extern "C" {
void* fn_109_1FF0(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_109_28A8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_109_1F6C(unsigned char* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_109_1FF0(object + 0xAC70, memberDeleting);
        fn_27_C74E8(object + 0xAC60, memberDeleting);
        fn_109_28A8(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
