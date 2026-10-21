#pragma force_active on
typedef unsigned int (*fn_ptr)(unsigned int, unsigned int, unsigned int, unsigned int);

struct X {
    fn_ptr vtable;
    unsigned int x04;
    unsigned int x08;
    unsigned int x0c;
    unsigned int x10;
    unsigned int x14;
    unsigned int x18;
    unsigned int x1c;
    unsigned int x20;
    unsigned int x24;
    unsigned int x28;
    unsigned int x2c;
};

unsigned int fn_80362488(struct X* p) {
    return p->vtable(p->x2c, p->x10, p->x14, p->x20);
}
