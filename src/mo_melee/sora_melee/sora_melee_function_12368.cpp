#pragma force_active on
typedef unsigned char u8;

struct Inner {
    char pad[0x5b];
    u8 flag;
};

struct Sub {
    struct Inner *a;
    struct Inner *b;
};

struct Obj {
    char pad[0x2c];
    struct Sub *sub;
};

extern "C" {
void fn_27_12368(struct Obj *self, u8 v) {
    struct Sub *s = self->sub;
    s->a->flag = v;
    if (s->b != 0) {
        s->b->flag = v;
    }
}
}
