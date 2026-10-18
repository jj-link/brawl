#pragma force_active on
class Stage {
public:
    void disableDevil();
};

extern signed char* g_cmAIController;

void Stage::disableDevil() {
    *((unsigned char*)this + 0xEB) = 0;
    signed char* ai = g_cmAIController;
    int v = ai[0x94];
    v = v & ~0x80;
    ai[0x94] = (signed char)v;
}
