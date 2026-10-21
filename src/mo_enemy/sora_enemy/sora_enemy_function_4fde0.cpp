#pragma force_active on
extern "C" {

void fn_41_2A480(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CB048(void*, short);
void fn_27_CB4A0(void*, short);
void fn_27_CF470(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_4FDE0(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5b84, v);
        __destroy_arr((char*)this_ + 0x5acc, fn_41_2A480, 8, 0x17);
        __destroy_arr((char*)this_ + 0x5a9c, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CB048((char*)this_ + 0x582c, v);
        fn_27_CF470((char*)this_ + 0x5310, v);
        short z = 0;
        fn_41_2CBC(this_, z);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
