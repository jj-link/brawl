#pragma force_active on
enum SndID { kSndDummy = 0 };

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" int fn_2_304A4() {
    return g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
