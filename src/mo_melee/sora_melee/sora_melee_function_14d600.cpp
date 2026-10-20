#pragma force_active on
struct ftCommonData {
    char pad[0x40];
    void* unk40;
};

extern ftCommonData* g_ftCommonData;

extern "C" {
void* fn_27_14D600()
{
    return g_ftCommonData->unk40;
}
}
