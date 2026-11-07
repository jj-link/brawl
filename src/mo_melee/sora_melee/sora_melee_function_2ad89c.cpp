#pragma force_active on
struct Entry { short a, b; char pad[8]; };
class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int size();
    int : 9;
    int first : 9;
    int last : 9;
    char pad[12];
    Entry e[1];
};

extern "C" int fn_27_2AD89C(Obj* self, int idx) {
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
