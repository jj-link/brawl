#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
} Entry;

extern Entry lbl_80455AA8[56];

int fn_800AFA04(int idx) {
    return lbl_80455AA8[idx].b;
}
}
