#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int field;
} FnObj;

int fn_66_11350(FnObj *p)
{
    return ((int)((p->field << 6) & 0xF0000000u)) >> 29;
}
}
