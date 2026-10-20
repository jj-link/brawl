#pragma force_active on
typedef struct Obj
{
    unsigned int pad0;
    unsigned int pad1;
    unsigned int value : 5;
    unsigned int reserved : 27;
} Obj;

extern "C" void fn_76_3F38(Obj *obj, unsigned int value)
{
    obj->value = value;
}
