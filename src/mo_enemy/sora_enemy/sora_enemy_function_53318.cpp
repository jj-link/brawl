#pragma force_active on
extern "C" {

void fn_41_532A8(void*, short);
void fn_27_CB4A0(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CAE44(void*, short);
void fn_27_D0C58(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_53318(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_532A8((char*)this_ + 0x6088, v);
        fn_27_CB4A0((char*)this_ + 0x6038, v);
        __destroy_arr((char*)this_ + 0x5F80, fn_41_2A480, 8, 0x17);
        __destroy_arr((char*)this_ + 0x5F68, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CAE44((char*)this_ + 0x5D3C, v);
        fn_27_D0C58((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
