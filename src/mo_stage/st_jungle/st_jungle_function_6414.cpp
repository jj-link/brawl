#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int field;
} S;

extern "C" {
int fn_51_6414(S *s)
{
    int t = (int)((s->field >> 27) & 7) << 29;
    return t >> 30;
}
}
