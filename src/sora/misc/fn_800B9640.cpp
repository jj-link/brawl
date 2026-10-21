#pragma force_active on
extern "C" int fn_8004D9E8(void* obj);
extern "C" void* g_GameGlobal;
extern "C" void* lbl_8059E080;
extern "C" void* lbl_8059E08C;

extern "C" void* fn_800B9640(void) {
    void* r;
    if (fn_8004D9E8(g_GameGlobal) != 0) {
        r = lbl_8059E080;
    } else {
        r = lbl_8059E08C;
    }
    return r;
}
