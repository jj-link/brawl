#pragma force_active on
struct Field {
    int : 2;
    int x : 2;
};

extern "C" int fn_72_4F44(void *obj)
{
    return ((Field *)((char *)obj + 8))->x;
}
