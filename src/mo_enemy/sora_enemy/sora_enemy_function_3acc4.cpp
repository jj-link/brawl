#pragma force_active on
extern "C" {

void fn_41_3AC54(void*, short);
void fn_27_CB4A0(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CA210(void*, short);
void fn_27_CE7B0(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_3ACC4(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_3AC54((char*)this_ + 0x59c8, v);
        fn_27_CB4A0((char*)this_ + 0x5978, v);
        __destroy_arr((char*)this_ + 0x5900, fn_41_2A480, 8, 0xf);
        __destroy_arr((char*)this_ + 0x58d0, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CA210((char*)this_ + 0x561c, v);
        fn_27_CE7B0((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
