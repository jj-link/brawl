#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18emTargetSearchUnitFv(void*, short);
void fn_27_CAE44(void*, short);
void fn_27_CE480(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_3A248(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5868, v);
        __destroy_arr((char*)this_ + 0x5800, (void (*)(void*, int))fn_41_2A480, 8, 0xd);
        __destroy_arr((char*)this_ + 0x57e8, (void (*)(void*, int))__dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CAE44((char*)this_ + 0x55bc, v);
        fn_27_CE480((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
