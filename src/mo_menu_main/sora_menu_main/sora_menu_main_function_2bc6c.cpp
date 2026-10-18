#pragma force_active on
enum SndID { SndID_None = 0 };

struct sndSystem {
    void playSE(SndID id, int a, int b, int c, int d);
};

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" void fn_2_2BC6C() {
    g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
