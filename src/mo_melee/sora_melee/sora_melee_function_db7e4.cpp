#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int unk8;
} FnStruct;

extern "C" int fn_27_DB7E4(FnStruct *p)
{
    return (int)(((p->unk8 >> 25) & 7) << 29) >> 30;
}
