#pragma force_active on
extern "C" {
void* fn_123_2008(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_123_28C0(void*, short);

void* fn_123_1F84(char* obj, short deleting) {
    if (obj) {
        short memberDeleting = -1;
        fn_123_2008(obj + 0xB878, memberDeleting);
        fn_27_C74E8(obj + 0xB868, memberDeleting);
        fn_123_28C0(obj, short(0));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
}
