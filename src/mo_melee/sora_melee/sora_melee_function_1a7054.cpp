#pragma force_active on
extern "C" {

typedef struct {
    unsigned int hi : 4;
    unsigned int rest : 28;
} FieldWord;

void fn_27_1A7054(void *obj, unsigned int value)
{
    FieldWord *p = (FieldWord *)((char *)obj + 8);
    p->hi = value;
}

}
