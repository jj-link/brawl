#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 8;
    unsigned int f : 4;
    unsigned int lo : 20;
} FnObj;

extern "C" {
void fn_54_6A10(FnObj *obj, unsigned int val)
{
    obj->f = val;
}
}
