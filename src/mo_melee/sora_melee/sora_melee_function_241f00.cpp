#pragma force_active on
typedef struct Obj {
    char pad[0x42];
    unsigned char unk42;
} Obj;

extern "C" {
bool fn_27_241F00(Obj *p)
{
    return p->unk42 == 1;
}
}
