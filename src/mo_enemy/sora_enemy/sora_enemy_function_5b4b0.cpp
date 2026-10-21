#pragma force_active on
extern "C" {

void* fn_41_5B440(void*, short);
void* fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CACAC(void*, short);
void* fn_27_D15E8(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_5B4B0(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_5B440((char*)this_ + 0x676C, v);
        fn_27_CB4A0((char*)this_ + 0x671C, v);
        __destroy_arr((char*)this_ + 0x665C, fn_41_2A480, 8, 0x18);
        __destroy_arr((char*)this_ + 0x6644, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x645C, v);
        fn_27_D15E8((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
