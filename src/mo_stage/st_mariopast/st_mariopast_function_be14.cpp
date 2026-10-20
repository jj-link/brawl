#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    unsigned int c;
} FnStruct;

int fn_48_BE14(FnStruct *p)
{
    return (int)((p->c >> 13) & 0x7F) << 25 >> 26;
}
}
