#pragma force_active on
enum SndID { SND_NONE = 0 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" void fn_2_1D3F0() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
