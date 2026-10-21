#pragma force_active on
typedef struct {
    void *a;
    void *b;
} Entry;

extern Entry lbl_805337B0[32];

Entry *fn_8033AE5C(int idx) {
    return &lbl_805337B0[idx];
}
