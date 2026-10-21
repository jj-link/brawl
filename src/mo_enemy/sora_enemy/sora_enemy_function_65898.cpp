#pragma force_active on
extern "C" {

void fn_41_65828(void*, short);
void fn_27_CB4A0(void*, short);
void fn_27_CACAC(void*, short);
void fn_27_CE618(void*, short);
void fn_41_2CBC(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);

void* fn_41_65898(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_65828((char*)this_ + 0x7184, v);
        fn_27_CB4A0((char*)this_ + 0x7134, v);
        __destroy_arr((char*)this_ + 0x707c, fn_41_2A480, 8, 0x17);
        __destroy_arr((char*)this_ + 0x7064, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x6e7c, v);
        fn_27_CE618((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
