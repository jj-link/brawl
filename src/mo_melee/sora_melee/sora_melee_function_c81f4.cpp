#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int size();
    int : 5;
    int first : 5;
    int last : 5;
    char pad[18];
    struct E { signed char a, b; char p[0x12]; } e[1];
};

extern "C" int fn_27_C81F4(Obj* self, int idx) {
    if (idx < 0 || idx >= self->size()) return -1;
    if (idx == 0) return self->first;
    if (idx == self->size() - 1) return self->last;
    int n = idx;
    int cur = self->first;
    if (idx > self->size() / 2) {
        n = self->size() - idx - 1;
        cur = self->last;
    }
    for (int i = 0; i < self->size(); i++) {
        if (i == n) return cur;
        if (idx > self->size() / 2) cur = self->e[cur].a;
        else cur = self->e[cur].b;
        if (cur < 0) break;
    }
    return -1;
}
