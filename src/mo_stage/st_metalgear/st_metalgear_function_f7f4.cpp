#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 8;
    unsigned int f : 4;
    unsigned int lo : 20;
} StObj;

extern "C" void fn_71_F7F4(StObj *obj, unsigned int v)
{
    obj->f = v;
}
