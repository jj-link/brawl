#pragma force_active on
enum SndID { };

class sndSystem {
public:
    int playSE(SndID, int, int, int, int);
};

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" int fn_2_237E8() {
    return g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
