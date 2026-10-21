#pragma force_active on
extern "C" {

void fn_41_67AE8(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_CAE44(void*, short);
void fn_27_D0130(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_67B58(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_67AE8((char*)this_ + 0x5D48, v);
        fn_27_CB4A0((char*)this_ + 0x5CF8, v);
        __destroy_arr((char*)this_ + 0x5C38, fn_41_2A480, 8, 0x18);
        __destroy_arr((char*)this_ + 0x5C08, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CAE44((char*)this_ + 0x59DC, v);
        fn_27_D0130((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
