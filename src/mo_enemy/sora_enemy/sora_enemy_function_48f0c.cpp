#pragma force_active on
extern "C" {

void* fn_27_CB4A0(void*, short);
void* fn_27_CA448(void*, short);
void* fn_27_CFC68(void*, short);
void fn_41_2CBC(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_48F0C(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5dcc, v);
        __destroy_arr((char*)this_ + 0x5c8c, fn_41_2A480, 0x8, 0x28);
        __destroy_arr((char*)this_ + 0x5c14, __dt__18emTargetSearchUnitFv, 0x18, 5);
        fn_27_CA448((char*)this_ + 0x591c, v);
        fn_27_CFC68((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
