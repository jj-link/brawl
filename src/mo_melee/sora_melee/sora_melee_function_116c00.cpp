#pragma force_active on
struct Fighter {
    unsigned char pad[0xA];
};
extern "C" void setCurry__7FighterFbi(void*, bool, int);

extern "C" void fn_27_116C00(void* p)
{
    unsigned char* b = (unsigned char*)p;
    if (b[0xF] == 6)
        setCurry__7FighterFbi(*(void**)(b + ((unsigned)b[0xA] << 3) + 0x34), true, -1);
}