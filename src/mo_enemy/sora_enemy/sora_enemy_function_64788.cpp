#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void* __dt__18emTargetSearchUnitFv(void*, short);
void fn_27_CACAC(void*, short);
void fn_27_CF140(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_64788(void* this_, short deleting) {
    if (this_ != 0) {
        short v = -1;
        short z = 0;
        fn_27_CB4A0((char*)this_ + 0x59f4, v);
        __destroy_arr((char*)this_ + 0x59cc, fn_41_2A480, 8, 5);
        __destroy_arr((char*)this_ + 0x59b4, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x57cc, v);
        fn_27_CF140((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, z);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
