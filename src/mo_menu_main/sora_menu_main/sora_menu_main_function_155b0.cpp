#pragma force_active on
enum SndID { SndID_dummy = 0 };

struct sndSystem {
    int playSE(SndID, int, int, int, int);
};

extern sndSystem* g_sndSystem;

extern "C" int fn_2_155B0() {
    return g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
