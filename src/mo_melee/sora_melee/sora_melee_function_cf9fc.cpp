#pragma force_active on
extern "C" {
typedef struct {
    int unk0;
    int unk4;
    unsigned int unk8;
} fn_27_CF9FC_arg;

void fn_27_CF9FC(fn_27_CF9FC_arg* p) {
    p->unk8 &= ~0x00400000;
}
}
