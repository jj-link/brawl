#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void fn_27_CB048(void*, short);
void fn_27_CE948(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_36F0C(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5A3C, v);
        __destroy_arr((char*)this_ + 0x5904, fn_41_2A480, 8, 0x27);
        __destroy_arr((char*)this_ + 0x58BC, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CB048((char*)this_ + 0x564C, v);
        fn_27_CE948((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
