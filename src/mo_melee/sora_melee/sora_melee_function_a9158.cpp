#pragma force_active on
struct soModuleAccesser
{
    unsigned char unk[0x10];
    unsigned int interval;
};

struct soTargetSearchUnit
{
    unsigned char unk0[4];
    soModuleAccesser *moduleAccesser;
    unsigned char unk8[0x0C];
    unsigned int interval;

    void initInterval(soModuleAccesser *);
};

void soTargetSearchUnit::initInterval(soModuleAccesser *)
{
    interval = moduleAccesser->interval;
}
