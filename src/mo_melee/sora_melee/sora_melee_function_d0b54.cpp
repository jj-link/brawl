#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int hi : 7;
    unsigned int f : 7;
    unsigned int lo : 18;
} FnState;

extern "C" void fn_27_D0B54(FnState* s, unsigned int v) {
    s->f = v;
}
