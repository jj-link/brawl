#pragma force_active on
extern "C" {

void fn_27_CB4A0(void*, short);
void fn_27_CACAC(void*, short);
void fn_27_CEFA8(void*, short);
void fn_41_2A480(void*, short);
void __dt__18emTargetSearchUnitFv(void*, short);
void fn_41_2CBC(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_58C40(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_27_CB4A0((char*)this_ + 0x5a44, v);
        __destroy_arr((char*)this_ + 0x599c, (void (*)(void*, int))fn_41_2A480, 8, 0x15);
        __destroy_arr((char*)this_ + 0x5984, (void (*)(void*, int))__dt__18emTargetSearchUnitFv, 0x18, 1);
        fn_27_CACAC((char*)this_ + 0x579c, v);
        fn_27_CEFA8((char*)this_ + 0x5310, v);
        fn_41_2CBC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
