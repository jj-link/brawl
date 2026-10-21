#pragma force_active on
struct FieldBits {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
};

extern "C" void fn_54_6948(void *obj, unsigned int val)
{
    FieldBits *p = (FieldBits *)((char *)obj + 8);
    p->b = val;
}
