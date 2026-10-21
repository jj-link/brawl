#pragma force_active on
extern "C" {
void* fn_41_37CA8(void*, short);
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CB048(void*, short);
void* fn_27_CEE10(void*, short);
void* fn_41_2CBC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_37D18(void* this_, short deleting) {
    if (this_ != 0) {
        char* members = static_cast<char*>(this_);
        short v = -1;
        fn_41_37CA8(members + 0x5B44, v);
        fn_27_CB4A0(members + 0x5AF4, v);
        __destroy_arr(members + 0x5A24, fn_41_2A480, 8, 0x1A);
        __destroy_arr(members + 0x59DC, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CB048(members + 0x576C, v);
        fn_27_CEE10(members + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
