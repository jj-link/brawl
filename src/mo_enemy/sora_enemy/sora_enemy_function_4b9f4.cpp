#pragma force_active on
extern "C" {

void fn_41_4B984(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CAE44(void*, short);
void fn_27_CFC68(void*, short);
void fn_41_2CBC(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_4B9F4(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_4B984((char*)this_ + 0x5cb0, v);
        fn_27_CB4A0((char*)this_ + 0x5c60, v);
        __destroy_arr((char*)this_ + 0x5b78, fn_41_2A480, 8, 0x1d);
        __destroy_arr((char*)this_ + 0x5b48, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CAE44((char*)this_ + 0x591c, v);
        fn_27_CFC68((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
