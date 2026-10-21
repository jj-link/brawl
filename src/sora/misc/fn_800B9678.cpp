#pragma force_active on
#pragma optimization_level 0

extern "C" int fn_8004D9E8(void* obj);
extern void* g_GameGlobal;
extern int lbl_8059E084;
extern int lbl_8059E094;

extern "C" int fn_800B9678(void) {
    if (fn_8004D9E8(g_GameGlobal)) {
        return lbl_8059E084;
    }
    return lbl_8059E094;
}
