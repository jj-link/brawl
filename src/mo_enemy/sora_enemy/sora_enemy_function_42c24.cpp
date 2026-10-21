#pragma force_active on
extern "C" {

void* fn_41_42BB4(void*, short);
void fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void* __dt__18emTargetSearchUnitFv(void*, short);
void fn_27_CA64C(void*, short);
void fn_27_CEE10(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_42C24(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_42BB4((char*)this_ + 0x5C70, v);
        fn_27_CB4A0((char*)this_ + 0x5C20, v);
        __destroy_arr((char*)this_ + 0x5B20, fn_41_2A480, 8, 0x20);
        __destroy_arr((char*)this_ + 0x5AA8, __dt__18emTargetSearchUnitFv, 0x18, 5);
        fn_27_CA64C((char*)this_ + 0x576C, v);
        fn_27_CEE10((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
