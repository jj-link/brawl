#pragma force_active on
struct Table {
    int a;
    int b;
    int flags;
};

extern "C" void* fn_27_D9C00(struct Table* t, int idx) {
    int i = (t->flags >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return (char*)t + 12 + i * 28;
}
