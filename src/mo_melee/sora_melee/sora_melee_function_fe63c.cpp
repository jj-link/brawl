#pragma force_active on
struct Blob {
    char pad[8];
    int flags;
};

extern "C" {
void* fn_27_FE63C(Blob* p, int idx) {
    int adj = (p->flags >> 30) + idx;
    if (adj >= 1) {
        adj -= 1;
    }
    return (char*)p + adj * 12 + 12;
}
}
