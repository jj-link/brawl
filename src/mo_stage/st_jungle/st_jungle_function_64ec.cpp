#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int pre : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} FlagWord;

extern "C" {
void fn_51_64EC(FlagWord *obj, unsigned int value)
{
    obj->f = value;
}
}
