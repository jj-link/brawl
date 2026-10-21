#pragma force_active on
extern "C" {

void fn_41_35D7C(void*, short);
void fn_27_CB4A0(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CA97C(void*, short);
void fn_27_CFE00(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_35DEC(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_35D7C((char*)this_ + 0x5f04, v);
        fn_27_CB4A0((char*)this_ + 0x5eb4, v);
        __destroy_arr((char*)this_ + 0x5de4, fn_41_2A480, 8, 0x1A);
        __destroy_arr((char*)this_ + 0x5d54, __dt__18emTargetSearchUnitFv, 0x18, 6);
        fn_27_CA97C((char*)this_ + 0x594c, v);
        fn_27_CFE00((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
