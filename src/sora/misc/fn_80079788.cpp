#pragma force_active on
struct sndSystem;
struct snd3DGenerator {
    void startSE(long p1, long p2);
};

extern sndSystem* g_sndSystem;
extern "C" void fn_80075C8C(sndSystem*, long, long, long);

void snd3DGenerator::startSE(long p1, long p2) {
    fn_80075C8C(g_sndSystem, p1, p2, 0);
}
