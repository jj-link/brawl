#pragma force_active on
struct Node {
    int pad0, f4, pad8;
    union {
        Node* fC;
        int iC;
    };
};

struct Src {
    float v[8];
    Node* n20;
    Node* n24;
};

struct Dst {
    int p0;
    float f4;
    int p8, pC;
    float v[8];
    Node* n30;
    int f34;
    Node* n38;
    int f3C;
};

extern "C" void fn_802CA920(Dst* d, Src* s) {
    if (d->n30 != 0) {
        float previous, current;
        previous = d->v[7];
        current = s->v[7];
        if (!(current < previous))
            return;
    }

    float a7, a6, a5, a4, a3, a2, a1, a0;
    a0 = s->v[0];
    a1 = s->v[1];
    a2 = s->v[2];
    a3 = s->v[3];
    a4 = s->v[4];
    a5 = s->v[5];
    a6 = s->v[6];
    a7 = s->v[7];
    d->v[0] = a0;
    Node* a = s->n20;
    d->v[1] = a1;
    d->v[2] = a2;
    d->v[3] = a3;
    d->v[4] = a4;
    d->v[5] = a5;
    d->v[6] = a6;
    d->v[7] = a7;
    while (a->iC)
        a = a->fC;
    d->n30 = a;
    Node* b = s->n24;
    d->f34 = s->n20->f4;
    while (b->iC)
        b = b->fC;
    d->n38 = b;
    Node* c = s->n24;
    float t = s->v[7];
    d->f3C = c->f4;
    d->f4 = t;
}
