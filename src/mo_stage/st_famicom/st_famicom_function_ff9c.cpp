#pragma force_active on
enum SndID { SND_1CE5 = 0x1ce5 };

class snd3DGenerator {
public:
    void playSE(SndID sndId, int a, int b, int c);
};

extern "C" void fn_68_FF9C(char* self)
{
    snd3DGenerator* gen = (snd3DGenerator*)(self + 0x1a0);
    gen->playSE(SND_1CE5, 0, 0, -1);
}
