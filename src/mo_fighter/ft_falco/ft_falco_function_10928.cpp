#pragma force_active on
typedef struct Obj
{
    char pad[0xa4];
    unsigned char a : 1;
    unsigned char f : 1;
} Obj;

extern "C" bool fn_108_10928(Obj *p)
{
    return p->f;
}
