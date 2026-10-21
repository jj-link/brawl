#pragma force_active on
extern "C" {

void fn_41_4E614(void*, short);
void fn_27_CB4A0(void*, short);
void fn_27_CB048(void*, short);
void fn_27_CF7A0(void*, short);
void fn_41_2CBC(void*, short);
void* fn_41_2A480(void*, short);
void __dt__18emTargetSearchUnitFv(void*, short);
void __destroy_arr(void*, void (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_4E684(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_4E614((char*)this_ + 0x5c5c, v);
        fn_27_CB4A0((char*)this_ + 0x5c0c, v);
        __destroy_arr((char*)this_ + 0x5b44, (void (*)(void*, short))fn_41_2A480, 8, 0x19);
        __destroy_arr((char*)this_ + 0x5afc, __dt__18emTargetSearchUnitFv, 0x18, 3);
        fn_27_CB048((char*)this_ + 0x588c, v);
        fn_27_CF7A0((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
