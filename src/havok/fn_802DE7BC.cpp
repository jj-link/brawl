#pragma force_active on
struct Obj {
    int x0;
    int x4;
    void* ptr;
};

extern "C" {
extern void fn_802F8F98(void*, void*, int);

void fn_802DE7BC(Obj* a, Obj* b) {
    if (a->ptr == 0) return;
    fn_802F8F98(b->ptr, a, 1);
}
}
