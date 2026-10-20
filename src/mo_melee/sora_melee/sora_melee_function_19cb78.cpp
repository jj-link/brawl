#pragma force_active on
struct fn_27_Obj {
    unsigned char pad[8];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" {
void fn_27_19CB78(fn_27_Obj* obj, unsigned int v)
{
    obj->b = v;
}
}
