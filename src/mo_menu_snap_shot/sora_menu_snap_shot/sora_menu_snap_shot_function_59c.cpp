#pragma force_active on
enum SndID { SND_ID_DUMMY = 0 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

extern "C" {
extern sndSystem* g_sndSystem;
}

extern "C" void fn_8_59C(char* self) {
    char* p = *(char**)(self + 0x1ac);
    *(int*)(p + 0x1d10) = 0;
    char* q = *(char**)(self + 0x1ac);
    *(int*)(q + 0x1bfc) = 0x16;
    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
}
