#pragma force_active on
extern "C" {

void fn_41_594A0(void*, short);
void fn_27_CB4A0(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void fn_27_CACAC(void*, short);
void fn_27_CFAD0(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_59510(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_594A0((char*)this_ + 0x5c34, v);
        fn_27_CB4A0((char*)this_ + 0x5be4, v);
        __destroy_arr((char*)this_ + 0x5aec, fn_41_2A480, 0x8, 0x1f);
        __destroy_arr((char*)this_ + 0x5ad4, __dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x58ec, v);
        fn_27_CFAD0((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
