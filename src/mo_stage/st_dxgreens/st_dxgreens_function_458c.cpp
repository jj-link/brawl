#pragma force_active on
extern "C" int fn_79_458C(void* this_);

struct S {
    void* _0;
    void* _4;
    int _8 : 6;
    signed int x : 6;
};

extern "C" int fn_79_458C(void* this_)
{
    S* s = (S*)this_;
    return s->x;
}
