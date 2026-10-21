#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CA448(void*, short);
void fn_27_D0C58(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_56930(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x61DC, v);
        __destroy_arr((char*)this_ + 0x6094, fn_41_2A480, 8, 0x29);
        __destroy_arr((char*)this_ + 0x6034, __dt__18emTargetSearchUnitFv, 0x18, 4);
        fn_27_CA448((char*)this_ + 0x5D3C, v);
        fn_27_D0C58((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
