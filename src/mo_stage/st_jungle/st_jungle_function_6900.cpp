#pragma force_active on
typedef struct {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} BitField;

extern "C" {
void fn_51_6900(void *p, unsigned int v);
}

extern "C" void fn_51_6900(void *p, unsigned int v)
{
    ((BitField *)((char *)p + 8))->b = v;
}
