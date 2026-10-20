#pragma force_active on
typedef struct St47 {
    int unk0;
    int unk4;
    unsigned int bits;
} St47;

extern "C" int fn_47_5044(St47 *p)
{
    return ((int)((p->bits << 8) & 0xF8000000u)) >> 28;
}
