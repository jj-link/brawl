#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int unk8;
} fn_27_1B2798_arg;

extern "C" {
int fn_27_1B2798(fn_27_1B2798_arg* p) {
    return (int)((p->unk8 << 8) & 0xF8000000u) >> 28;
}
}
