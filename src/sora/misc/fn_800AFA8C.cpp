#pragma force_active on
extern "C" int fn_8004D9E8(void* obj);
extern void* g_GameGlobal;
extern int lbl_80456338[];
extern int lbl_80456564[];

extern "C" int fn_800AFA8C(int idx) {
    if (fn_8004D9E8(g_GameGlobal) != 0) {
        if (lbl_80456338[idx] == 0) {
            return lbl_80456564[idx];
        }
        return lbl_80456338[idx];
    }
    return lbl_80456564[idx];
}
