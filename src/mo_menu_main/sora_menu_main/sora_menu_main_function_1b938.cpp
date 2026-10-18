#pragma force_active on
class sndSystem;

enum SndID {};

class sndSystem {
public:
    int playSE(SndID, int, int, int, int);
};

extern sndSystem* g_sndSystem;

extern "C" int fn_2_1B938() {
    return g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
