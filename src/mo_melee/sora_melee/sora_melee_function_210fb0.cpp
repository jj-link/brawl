#pragma force_active on
typedef struct {
    unsigned char pad[0x9c];
    short unk9c;
    unsigned char pad2[2];
    float unkA0;
} FnObj;

extern const float lbl_27_rodata_30C4;

extern "C" void fn_27_210FB0(FnObj *p)
{
    p->unk9c = 0xb4;
    p->unkA0 = p->unkA0 * lbl_27_rodata_30C4;
}
