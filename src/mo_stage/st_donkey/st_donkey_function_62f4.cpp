#pragma force_active on
typedef struct FnFlags {
    int pad[2];
    unsigned int a : 6;
    unsigned int flag : 1;
    unsigned int rest : 25;
} FnFlags;

extern "C" unsigned int fn_50_62F4(FnFlags *p)
{
    return p->flag;
}
