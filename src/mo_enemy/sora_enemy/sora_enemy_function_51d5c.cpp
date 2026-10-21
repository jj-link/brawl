#pragma force_active on
extern "C" {

void fn_41_51CEC(void*, short);
void fn_27_CB4A0(void*, short);
void fn_27_CACAC(void*, short);
void fn_27_CEFA8(void*, short);
void fn_41_2CBC(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_51D5C(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_51CEC((char*)this_ + 0x5A64, v);
        fn_27_CB4A0((char*)this_ + 0x5A14, v);
        __destroy_arr((char*)this_ + 0x599C, fn_41_2A480, 8, 0xF);
        __destroy_arr((char*)this_ + 0x5984, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x579C, v);
        fn_27_CEFA8((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
