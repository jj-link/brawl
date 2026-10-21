#pragma force_active on
enum SndID { SND_ID_NONE = 0 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern sndSystem* g_sndSystem;
extern "C" void fn_80074EF8(sndSystem* sys, SndID id, int handle, int a, int b, int c, int d);

class snd3DGenerator {
public:
    void playSE(SndID id, int a, int b, int c);
    int m_handle;
};

void snd3DGenerator::playSE(SndID id, int a, int b, int c) {
    if (m_handle != 0) {
        fn_80074EF8(g_sndSystem, id, m_handle, a, b, 0, c);
    } else {
        g_sndSystem->playSE(id, a, b, 0, c);
    }
}
