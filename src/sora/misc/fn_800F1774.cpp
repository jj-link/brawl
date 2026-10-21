#pragma force_active on
// fn_800F1774: returns the global sound system pointer/handle (sda21-relative load).

extern int g_sndSystem;

extern "C" int fn_800F1774(void) {
    return g_sndSystem;
}
