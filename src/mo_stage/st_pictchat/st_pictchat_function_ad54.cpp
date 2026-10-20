#pragma force_active on
extern "C" {

typedef struct {
    int unk0;
    int unk4;
    unsigned int hi : 4;
    unsigned int field : 5;
    unsigned int lo : 23;
} Packed;

int fn_73_AD54(Packed *p)
{
    return ((int)(p->field << 27)) >> 28;
}

}
