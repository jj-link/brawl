#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int flag;
};

extern "C" unsigned int fn_27_54414(const Obj *p)
{
    return (p->flag >> 4) & 1;
}
