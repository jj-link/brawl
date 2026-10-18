#pragma force_active on
class sndSystem;

extern "C" extern sndSystem* g_sndSystem;

extern "C" sndSystem* fn_10_1284() {
    return g_sndSystem;
}
