#pragma force_active on
extern "C" {

void fn_41_2A480(void*, short);
void __dt__18emTargetSearchUnitFv(void*, short);
void fn_27_CB4A0(void*, short);
void fn_27_CA7E4(void*, short);
void fn_27_CE2E8(void*, short);
void fn_41_2CBC(void*, short);
void __destroy_arr(void*, void (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_3F70C(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5a94, v);
        __destroy_arr((char*)this_ + 0x5984, fn_41_2A480, 8, 0x22);
        __destroy_arr((char*)this_ + 0x58dc, __dt__18emTargetSearchUnitFv, 0x18, 7);
        fn_27_CA7E4((char*)this_ + 0x555c, v);
        fn_27_CE2E8((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
