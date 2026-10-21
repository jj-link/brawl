#pragma force_active on
class gfPadSystem {
public:
    char pad0[0x35];
    char unk35;
    int readGameDataRequest(int, int, int, int);
};

extern "C" void wpadGameDataCallback__11gfPadSystemFi(int);
extern "C" int fn_802250C8(int, int, int, int, void (*)(int));

int gfPadSystem::readGameDataRequest(int a, int b, int c, int d) {
    unk35 &= 0xFFFFFF7F;
    return fn_802250C8(a, b, c, d, wpadGameDataCallback__11gfPadSystemFi) == 0;
}
