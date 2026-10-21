#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} Fields;

void fn_73_AD64(void *obj, unsigned long val)
{
    Fields *p = (Fields *)((char *)obj + 8);
    p->b = val;
}
}
