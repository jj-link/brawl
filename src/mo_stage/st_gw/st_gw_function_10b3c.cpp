#pragma force_active on
extern "C" {
typedef struct Obj {
    int pad[2];
    unsigned int word;
} Obj;

int fn_63_10B3C(Obj *p)
{
    return (int)((p->word << 4) & 0xE0000000u) >> 30;
}
}
