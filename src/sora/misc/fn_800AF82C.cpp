#pragma force_active on

typedef struct {
    unsigned char pad[3];
    unsigned char v;
    unsigned char pad2[12];
} SelEntry;

extern "C" {

extern const SelEntry lbl_80455458[];

extern "C" unsigned char exchangeMuSelchkind2MuStockchkind__6muMenuFi(int idx) {
    return lbl_80455458[idx].v;
}

}
