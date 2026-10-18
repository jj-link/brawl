#pragma force_active on
extern "C" {

void fn_41_157D8(void*, short);
void fn_41_156DC(void*, short);
void fn_41_15640(void*, short);
void fn_41_1ADA0(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_41_155DC(void*, short);
void __dl__FPv(void*);

void* fn_41_15848(void* this_, short deleting) {
    if (this_) {
        short v = -1;
        fn_41_157D8((char*)this_ + 0xaf0, v);
        fn_41_156DC((char*)this_ + 0x740, v);
        fn_41_15640((char*)this_ + 0x72c, v);
        __destroy_arr((char*)this_ + 0x2c, fn_41_1ADA0, 0xe0, 8);
        fn_41_155DC(this_, 0);
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
