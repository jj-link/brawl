#pragma force_active on
struct SoObj {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

extern "C" {
void fn_27_390478(SoObj *obj, unsigned int v)
{
    obj->b = v;
}
}
