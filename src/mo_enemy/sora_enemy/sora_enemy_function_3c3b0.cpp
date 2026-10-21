#pragma force_active on

extern "C" {
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void* fn_27_CACAC(void*, short);
void* fn_27_CEE10(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_3C3B0(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_27_CB4A0(members + 0x5a2c, memberDeleting);
        __destroy_arr(members + 0x596c, fn_41_2A480, 8, 0x18);
        __destroy_arr(members + 0x5954, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC(members + 0x576c, memberDeleting);
        fn_27_CEE10(members + 0x5310, memberDeleting);
        fn_41_2CBC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
