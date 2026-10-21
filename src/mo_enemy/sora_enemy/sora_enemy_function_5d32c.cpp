#pragma force_active on
extern "C" {
void fn_41_5D2BC(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_CACAC(void*, short);
void fn_27_D12B8(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_5D32C(void* this_, short deleting) {
    if (this_) {
        char* members = static_cast<char*>(this_);
        short memberDeleting = -1;
        fn_41_5D2BC(members + 0x643C, memberDeleting);
        fn_27_CB4A0(members + 0x63EC, memberDeleting);
        __destroy_arr(members + 0x635C, fn_41_2A480, 8, 0x12);
        __destroy_arr(members + 0x6344, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC(members + 0x615C, memberDeleting);
        fn_27_D12B8(members + 0x5310, memberDeleting);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
