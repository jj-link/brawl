#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void fn_27_CB048(void*, short);
void fn_27_CFE00(void*, short);
void fn_41_2CBC(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __dl__FPv(void*);

void* fn_41_484C0(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5cd4, v);
        __destroy_arr((char*)this_ + 0x5bec, fn_41_2A480, 8, 0x1D);
        __destroy_arr((char*)this_ + 0x5bbc, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CB048((char*)this_ + 0x594c, v);
        fn_27_CFE00((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
