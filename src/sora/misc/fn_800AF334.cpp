#pragma force_active on
typedef unsigned char u8;

struct lbl_80407A40_t {
    u8 unk0[2];
    u8 unk2;
};

extern "C" const lbl_80407A40_t lbl_80407A40[];

extern "C" u8 exchangeMuCharKindToMuStockchkind__6muMenuFiii(int kind, int, int) {
    return lbl_80407A40[kind].unk2;
}
