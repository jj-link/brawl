#pragma force_active on
enum SndID { SND_ID_DUMMY = 0 };

class sndSystem {
public:
    int playSE(SndID id, int a, int b, int c, int d);
};

extern "C" {
extern sndSystem* g_sndSystem;
void fn_2_14088();
}

extern "C" void fn_2_14088() {
    g_sndSystem->playSE(static_cast<SndID>(0x14), -1, 0, 0, -1);
}
