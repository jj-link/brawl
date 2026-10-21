#pragma force_active on

struct Fields {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
};

extern "C" void fn_73_AA98(void *obj, unsigned long val)
{
    Fields *p = (Fields *)((char *)obj + 8);
    p->b = val;
}
