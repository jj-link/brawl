#pragma force_active on
extern "C" {

void* fn_41_60AF8(void*, short);
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CB048(void*, short);
void* fn_27_D0DF0(void*, short);
void* fn_41_2CBC(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_60B68(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_60AF8((char*)this_ + 0x629c, v);
        fn_27_CB4A0((char*)this_ + 0x624c, v);
        __destroy_arr((char*)this_ + 0x6144, fn_41_2A480, 8, 0x21);
        __destroy_arr((char*)this_ + 0x60fc, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CB048((char*)this_ + 0x5e8c, v);
        fn_27_D0DF0((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, (short)0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
