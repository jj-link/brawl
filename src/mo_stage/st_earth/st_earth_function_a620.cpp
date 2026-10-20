#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int hi : 4;
    unsigned int nib : 4;
    unsigned int lo : 24;
} Obj;

extern "C" {
void fn_66_A620(Obj *obj, unsigned int v)
{
    obj->nib = v;
}
}
