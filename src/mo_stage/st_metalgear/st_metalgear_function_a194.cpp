#pragma force_active on
typedef struct Obj {
    int unused0;
    int unused1;
    unsigned int pad : 4;
    int val : 4;
    unsigned int rest : 24;
} Obj;

extern "C" {
int fn_71_A194(Obj *p)
{
    return p->val;
}
}
