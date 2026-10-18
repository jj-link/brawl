#pragma force_active on
enum SndID { SND_ID_DUMMY = 0 };

class snd3DGenerator {
public:
    void playSE(SndID id, int a, int b, int c);
};

extern "C" void fn_68_FFB4(char* p)
{
    ((snd3DGenerator*)(p + 0x1a0))->playSE((SndID)0x1ce7, 0, 0, -1);
}
