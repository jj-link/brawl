#pragma force_active on
extern "C" {
void fn_41_3CEEC(void*, short);
void fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void fn_27_CA448(void*, short);
void fn_27_CEC78(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_3CF5C(void* this_, short deleting) {
    if (this_ != 0) {
        short v = -1;
        fn_41_3CEEC((char*)this_ + 0x5B84, v);
        fn_27_CB4A0((char*)this_ + 0x5B34, v);
        __destroy_arr((char*)this_ + 0x5A94, fn_41_2A480, 8, 0x14);
        __destroy_arr((char*)this_ + 0x5A34, __dt__18emTargetSearchUnitFv, 0x18, 4);
        fn_27_CA448((char*)this_ + 0x573C, v);
        fn_27_CEC78((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
