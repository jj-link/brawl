#pragma force_active on
extern "C" {

struct FnBits {
    unsigned int hi : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
};

struct FnObj {
    unsigned int w0;
    unsigned int w1;
    struct FnBits w2;
};

void fn_71_A044(struct FnObj *obj, unsigned int v)
{
    obj->w2.f = v;
}

}
