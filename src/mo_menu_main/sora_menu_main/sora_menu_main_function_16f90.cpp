#pragma force_active on
enum SndID { SndID_none = 0 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern sndSystem* g_sndSystem;

extern "C" void fn_2_16F90() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
