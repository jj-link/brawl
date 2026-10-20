#pragma force_active on
extern "C" {
struct Fn27Target {
    int unk0;
    int unk4;
    unsigned int flags;
};

void fn_27_D01E4(struct Fn27Target *p) {
    p->flags |= 0x400;
}
}
