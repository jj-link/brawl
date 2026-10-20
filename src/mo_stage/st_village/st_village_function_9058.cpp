#pragma force_active on
typedef struct SomeObj
{
    unsigned int pad[2];
    unsigned int flag : 2;
    unsigned int rest : 30;
} SomeObj;

extern "C" {
void fn_70_9058(SomeObj *obj, unsigned int value)
{
    obj->flag = value;
}
}
