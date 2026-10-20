#pragma force_active on
typedef struct
{
    unsigned int pad[2];
    unsigned int field : 4;
    unsigned int rest : 28;
} StFlags;

extern "C" void fn_54_E4B4(StFlags *p, unsigned int v)
{
    p->field = v;
}
