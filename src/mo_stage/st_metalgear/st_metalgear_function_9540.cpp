#pragma force_active on
typedef struct StObj {
    int unk0;
    int unk4;
    unsigned int f0 : 6;
    unsigned int f1 : 1;
    unsigned int f2 : 25;
} StObj;

extern "C" int fn_71_9540(StObj *p)
{
    return p->f1;
}
