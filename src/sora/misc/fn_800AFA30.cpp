#pragma force_active on
extern "C" int fn_8004D9E8(void* obj);
extern void* g_GameGlobal;
extern int lbl_804561E4[];
extern int lbl_80456564[];

struct muMenu {
    static int exchangeMuStockchkind2MuCharName(int idx);
};

int muMenu::exchangeMuStockchkind2MuCharName(int idx) {
    if (fn_8004D9E8(g_GameGlobal) != 0) {
        return lbl_804561E4[idx];
    }
    return lbl_80456564[idx];
}
