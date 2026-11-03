#pragma force_active on
struct Hdr {
    char pad[0x1c];
    int off1c;
    int off20;
    char pad2[0xc];
    unsigned short n0;
    unsigned short n1;
};

struct Obj {
    Hdr *hdr;
};

extern "C" void fn_801938D4(Obj *obj) {
    Hdr *h = obj->hdr;
    int n0 = h->n0;
    int n1 = h->n1;
    int *a = h->off1c ? (int *)((char *)h + h->off1c) : 0;
    int *b = h->off20 ? (int *)((char *)h + h->off20) : 0;
    int i = 0;
    if (n0 > 0) {
        for (; i < n0; i++) {
            a[i] = 0;
        }
    }
    int j = 0;
    if (n1 > 0) {
        for (; j < n1; j++) {
            b[j] = 0;
        }
    }
}