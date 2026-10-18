#pragma force_active on
struct Obj {
    void *ptr;
    unsigned char state;
};

extern "C" int fn_113_23504(Obj *obj)
{
    if (obj->state == 1)
        return -1;
    return *(int *)obj->ptr;
}
