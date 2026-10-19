#pragma force_active on
extern "C" {
void __dt__15grGimmickSpringFv(void* this_, int flag);
void __dl__FPv(void* ptr);

void* fn_89_18C4(void* this_, int flag) {
    if (this_ != 0) {
        __dt__15grGimmickSpringFv(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
}
