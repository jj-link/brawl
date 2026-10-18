#pragma force_active on
enum SndID { SND_ID_ZERO = 0 };

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern sndSystem* g_sndSystem;

extern "C" int fn_2_2CE18() {
    return g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
