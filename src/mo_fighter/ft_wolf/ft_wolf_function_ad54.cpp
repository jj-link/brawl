#pragma force_active on
extern "C" {
void* fn_125_7F28(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_125_19D0(char*, short);
void __dl__FPv(void*);

void* fn_125_AD54(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_125_7F28(object + 0x1CC8C, memberDeleting);
        fn_27_C74E8(object + 0x1CC74, memberDeleting);
        fn_125_19D0(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
