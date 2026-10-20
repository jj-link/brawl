#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int field;
} S72;

int fn_72_5108(S72 *s)
{
    return (int)((s->field << 4) & 0xE0000000) >> 30;
}
}
