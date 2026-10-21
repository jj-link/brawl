#pragma force_active on
typedef struct {
    int pad[0x54 / 4];
    int unk54;
    int unk58;
} F;

int fn_80374C00(void *arg0) {
    F *f = (F *)arg0;
    return f->unk54 - f->unk58;
}
