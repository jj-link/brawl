#pragma force_active on
class sndSystem {
public:
    unsigned int getBGMId();
    void playBGM(int id, unsigned long flags, bool enabled);
};

extern sndSystem* g_sndSystem;

extern "C" void fn_5_124B4() {
    if (g_sndSystem->getBGMId() != 9999U) {
        g_sndSystem->playBGM(9999, 0, true);
    }
}
