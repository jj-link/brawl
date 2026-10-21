#pragma force_active on
extern "C" {

void fn_41_3E664(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CB048(void*, short);
void fn_27_CEC78(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_3E6D4(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_3E664((char*)this_ + 0x5b40, v);
        fn_27_CB4A0((char*)this_ + 0x5aec, v);
        __destroy_arr((char*)this_ + 0x59f4, fn_41_2A480, 8, 0x1f);
        __destroy_arr((char*)this_ + 0x59ac, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CB048((char*)this_ + 0x573c, v);
        fn_27_CEC78((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
