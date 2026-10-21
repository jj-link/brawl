#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    int c;
    int d;
} MuStockEntry;

extern MuStockEntry lbl_80455458[];

int exchangeMuSelchkind2MuStockchkind__6muMenuFiii(int idx, int p1, int p2) {
    return lbl_80455458[idx].b;
}
}
