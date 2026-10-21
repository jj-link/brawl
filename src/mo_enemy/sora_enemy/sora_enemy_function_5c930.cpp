#pragma force_active on
extern "C" {

void fn_27_C9550(void*, short);
void fn_27_CB4A0(void*, short);
void fn_27_CA448(void*, short);
void fn_27_CE150(void*, short);
void fn_41_2CBC(void*, short);
void fn_41_2A480(void*, short);
void __dt__18emTargetSearchUnitFv(void*, short);
void __destroy_arr(void*, void (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_5C930(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_C9550((char*)this_ + 0x6cb4, v);
        fn_27_CB4A0((char*)this_ + 0x6c64, v);
        __destroy_arr((char*)this_ + 0x6bd4, fn_41_2A480, 8, 0x12);
        __destroy_arr((char*)this_ + 0x6ba4, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CA448((char*)this_ + 0x68ac, v);
        fn_27_CE150((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
