#pragma force_active on
extern "C" {
int exchangeMuSelchkind2MuStockchkind__6muMenuFi(int);
int exchangeGmCharacterKind2Something__6muMenuFi(int);

float fn_40_3EFFC(int kind) {
    int sel = exchangeMuSelchkind2MuStockchkind__6muMenuFi(kind);
    int k = exchangeGmCharacterKind2Something__6muMenuFi(sel);
    return k * 10 + 1;
}
}