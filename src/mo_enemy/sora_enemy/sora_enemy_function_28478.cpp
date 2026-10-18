#pragma force_active on
struct EnemyCtx {
    void *a;
    unsigned char flag;
    void *b;
    void *c;
};

extern "C" {
void fn_41_28478(struct EnemyCtx *self, void *p4, void *p5, void *p6) {
    self->a = p4;
    self->flag = 0;
    self->b = p5;
    self->c = p6;
}
}
