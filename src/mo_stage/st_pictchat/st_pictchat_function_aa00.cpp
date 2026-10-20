#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} Fields;

void fn_73_AA00(void *obj, unsigned long val)
{
    Fields *p = (Fields *)((char *)obj + 8);
    p->b = val;
}
}
