#pragma force_active on
class MuMsg {
public:
    void getWScale(unsigned long idx, float f);
    char pad[0xc];
    char* base;
};

void MuMsg::getWScale(unsigned long idx, float f)
{
    *(float*)(base + idx * 0x48 + 0x2c) = f;
}
