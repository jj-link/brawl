#pragma force_active on
enum SndID { SndID_dummy = 0 };

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" void fn_18_48C8() {
    g_sndSystem->playSE(static_cast<SndID>(0), -1, 0, 0, -1);
}
