#pragma force_active on
struct fn_27_C5B08_obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_C5B08(fn_27_C5B08_obj* p) {
    p->flags |= 0x02000000;
}
}
