#pragma force_active on
typedef struct Ent {
    char pad[13];
    signed char flag;
    char rest[2];
} Ent;

typedef struct Owner {
    char pad[8];
    Ent *arr;
    int idx;
} Owner;

extern "C" {
int fn_27_9A7F8(Owner *p)
{
    return !(p->arr[p->idx].flag < 0);
}
}
