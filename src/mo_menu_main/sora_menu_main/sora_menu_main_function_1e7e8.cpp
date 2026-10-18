#pragma force_active on
class sndSystem;

enum SndID { SND_ID_NONE = 0 };

extern "C" {
extern sndSystem* g_sndSystem;
}

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern "C" void fn_2_1E7E8() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
