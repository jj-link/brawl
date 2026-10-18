#pragma force_active on
class sndSystem;
enum SndID { SndID_dummy = 0 };
extern sndSystem* g_sndSystem;

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern "C" int fn_2_14668() {
    return g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
