#pragma force_active on
class sndSystem;
extern sndSystem* g_sndSystem;

enum SndID { SND_ID_0 = 0 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern "C" void fn_18_7A28() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
