#pragma force_active on
enum SndID {};

class snd3DGenerator {
public:
    void playSE(SndID id, int a, int b, int c);
};

extern "C" void fn_68_11828(char* self) {
    reinterpret_cast<snd3DGenerator*>(self + 0x1a0)->playSE((SndID)0x1ce6, 0, 0, -1);
}
