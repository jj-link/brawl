#pragma force_active on
enum SndID { SND_ID_NONE = 0 };

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern sndSystem* g_sndSystem;

extern "C" int fn_2_2DD10() {
    return g_sndSystem->playSE(SND_ID_NONE, -1, 0, 0, -1);
}
