#pragma force_active on
struct Entry { signed char a, b; char pad[10]; };
class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual void fn_27_FF68();
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
    int : 5;
    int first : 5;
    int last : 5;
    char pad[10];
    Entry e[1];
};
extern "C" int fn_27_2ACB8C(Class_C80* self, int idx) {
    if (idx < 0 || idx >= self->fn_27_FFF0()) return -1;
    if (idx == 0) return self->first;
    if (idx == self->fn_27_FFF0() - 1) return self->last;
    int n = idx;
    int cur = self->first;
    if (idx > self->fn_27_FFF0() / 2) {
        n = self->fn_27_FFF0() - idx - 1;
        cur = self->last;
    }
    for (int i = 0; i < self->fn_27_FFF0(); i++) {
        if (i == n) return cur;
        if (idx > self->fn_27_FFF0() / 2) cur = self->e[cur].a;
        else cur = self->e[cur].b;
        if (cur < 0) break;
    }
    return -1;
}