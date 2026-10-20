#pragma force_active on
extern "C" {
void* fn_97_20AC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_97_2964(void*, short);
void __dl__FPv(void*);

void* fn_97_2028(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_97_20AC(object + 0x1B01C, memberDeleting);
        fn_27_C74E8(object + 0x1B00C, memberDeleting);
        fn_97_2964(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
