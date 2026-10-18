#pragma force_active on
class sndSystem;
extern sndSystem* g_sndSystem;

enum SndID { SND_ID_NONE = 0 };

class sndSystem {
public:
    void playSE(SndID, int, int, int, int);
};

extern "C" void fn_2_28DF4() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
