#pragma force_active on
extern "C" {
void* fn_41_55884(void*, short);
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CAE44(void*, short);
void* fn_27_D0C58(void*, short);
void* fn_41_2CBC(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_558F4(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_55884((char*)this_ + 0x6060, v);
        fn_27_CB4A0((char*)this_ + 0x6010, v);
        __destroy_arr((char*)this_ + 0x5F80, fn_41_2A480, 8, 0x12);
        __destroy_arr((char*)this_ + 0x5F68, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CAE44((char*)this_ + 0x5D3C, v);
        fn_27_D0C58((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
}
