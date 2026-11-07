#pragma force_active on
struct Entry { signed char a, b; char pad[18]; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    int : 5;
    int first : 5;
    int last : 5;
    char pad[18];
    Entry e[1];
};
extern "C" int fn_27_2BC3B0(Object_vptr_0* self, int idx) {
    if (idx < 0 || idx >= self->slot3()) return -1;
    if (idx == 0) return self->first;
    if (idx == self->slot3() - 1) return self->last;
    int n = idx;
    int cur = self->first;
    if (idx > self->slot3() / 2) {
        n = self->slot3() - idx - 1;
        cur = self->last;
    }
    for (int i = 0; i < self->slot3(); i++) {
        if (i == n) return cur;
        if (idx > self->slot3() / 2) cur = self->e[cur].a;
        else cur = self->e[cur].b;
        if (cur < 0) break;
    }
    return -1;
}