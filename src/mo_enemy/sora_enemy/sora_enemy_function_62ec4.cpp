#pragma force_active on
extern "C" {

void fn_41_62E54(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_CAE44(void*, short);
void fn_27_CDFB4(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_62EC4(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_62E54((char*)this_ + 0x6a58, v);
        fn_27_CB4A0((char*)this_ + 0x6a08, v);
        __destroy_arr((char*)this_ + 0x6958, fn_41_2A480, 8, 0x16);
        __destroy_arr((char*)this_ + 0x6928, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CAE44((char*)this_ + 0x66fc, v);
        fn_27_CDFB4((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
