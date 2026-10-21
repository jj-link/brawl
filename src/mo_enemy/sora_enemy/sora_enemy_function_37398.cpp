#pragma force_active on
extern "C" {

void fn_27_63EBC(void*, short);
void fn_27_CB4A0(void*, short);
void fn_41_2A480(void*, int);
void __dt__18emTargetSearchUnitFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_CB048(void*, short);
void fn_27_CEAE0(void*, short);
void fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_37398(void* this_, short deleting) {
    if (this_) {
        short memberDeleting = -1;
        fn_27_63EBC((char*)this_ + 0x5A04, memberDeleting);
        fn_27_CB4A0((char*)this_ + 0x59B4, memberDeleting);
        __destroy_arr((char*)this_ + 0x594C, fn_41_2A480, 8, 0xD);
        __destroy_arr((char*)this_ + 0x591C, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CB048((char*)this_ + 0x56AC, memberDeleting);
        fn_27_CEAE0((char*)this_ + 0x5310, memberDeleting);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
