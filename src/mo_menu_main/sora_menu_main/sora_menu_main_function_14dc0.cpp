#pragma force_active on
enum SndID { SND_NONE = -1 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern sndSystem* g_sndSystem;

extern "C" void fn_2_14DC0() {
    g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
