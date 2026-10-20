#pragma force_active on
typedef struct Entry {
    int a;
    int b;
} Entry;

extern "C" {
Entry *fn_40_2898C(Entry *base, int idx) {
    return (Entry *)((char *)base + (idx << 3) + 0xc);
}
}
