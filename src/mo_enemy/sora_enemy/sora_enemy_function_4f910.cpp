#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void fn_27_CB048(void*, short);
void fn_27_D02C8(void*, short);
void fn_41_2A480(void*, short);
void __dt__18emTargetSearchUnitFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_4F910(void* this_, short deleting) {
    if (this_ != 0) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5db4, v);
        __destroy_arr((char*)this_ + 0x5cc4, (void (*)(void*, int))fn_41_2A480, 0x8, 0x1e);
        __destroy_arr((char*)this_ + 0x5c7c, (void (*)(void*, int))__dt__18emTargetSearchUnitFv, 0x18, 0x3);
        fn_27_CB048((char*)this_ + 0x5a0c, v);
        fn_27_D02C8((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
