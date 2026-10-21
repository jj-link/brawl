#pragma force_active on
struct MuMsg {
    char pad[0xc];
    char *list;

    void setWScale(unsigned long idx, float f);
};

void MuMsg::setWScale(unsigned long idx, float f)
{
    *(float *)(list + idx * 0x48 + 0x28) = f;
}
