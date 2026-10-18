#pragma force_active on
extern "C" {

typedef struct FighterObj
{
    void *ptr;
    unsigned char flag;
    float value;
    unsigned char c;
} FighterObj;

void fn_107_1F764(FighterObj *obj, void *p, float f, unsigned char b)
{
    obj->ptr = p;
    obj->flag = 0;
    obj->value = f;
    obj->c = b;
}

}
