#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c : 4;
    unsigned int d : 2;
    unsigned int e : 26;
} Obj;

extern "C" void fn_51_64B0(Obj *obj, unsigned int val)
{
    obj->d = val;
}
