#pragma force_active on
class sndSystem;

enum SndID { };

extern "C" {
extern sndSystem* g_sndSystem;
int fn_2_16A40();
}

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern "C" int fn_2_16A40() {
    return g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
