#pragma force_active on
extern "C" {

void fn_41_57474(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_CA97C(void*, short);
void fn_27_D0790(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_574E4(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_57474((char*)this_ + 0x61f4, v);
        fn_27_CB4A0((char*)this_ + 0x61a4, v);
        __destroy_arr((char*)this_ + 0x600c, fn_41_2A480, 8, 0x33);
        __destroy_arr((char*)this_ + 0x5f34, __dt__18emTargetSearchUnitFv, 0x18, 9);
        fn_27_CA97C((char*)this_ + 0x5b2c, v);
        fn_27_D0790((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
