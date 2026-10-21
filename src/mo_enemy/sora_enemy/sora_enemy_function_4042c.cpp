#pragma force_active on
extern "C" {

void fn_41_403BC(void*, short);
void fn_27_CB4A0(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CAB14(void*, short);
void fn_27_D0928(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_4042C(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_403BC((char*)this_ + 0x643C, v);
        fn_27_CB4A0((char*)this_ + 0x63EC, v);
        __destroy_arr((char*)this_ + 0x610C, fn_41_2A480, 8, 0x5C);
        __destroy_arr((char*)this_ + 0x5FEC, __dt__18emTargetSearchUnitFv, 0x18, 0xC);
        fn_27_CAB14((char*)this_ + 0x5B5C, v);
        fn_27_D0928((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
