#pragma force_active on
extern "C" {

void fn_41_69D80(void*, short);
void fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18emTargetSearchUnitFv(void*, short);
void fn_27_CACAC(void*, short);
void fn_27_D0460(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_69DF0(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_69D80((char*)this_ + 0x5d4c, v);
        fn_27_CB4A0((char*)this_ + 0x5cfc, v);
        __destroy_arr((char*)this_ + 0x5c3c, (void (*)(void*, int))fn_41_2A480, 8, 0x18);
        __destroy_arr((char*)this_ + 0x5c24, (void (*)(void*, int))__dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x5a3c, v);
        fn_27_D0460((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
