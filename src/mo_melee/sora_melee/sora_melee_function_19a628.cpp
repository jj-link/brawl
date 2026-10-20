#pragma force_active on
typedef unsigned int u32;

struct BitsField {
    u32 top : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" {
void fn_27_19A628(void* p, u32 v)
{
    BitsField* b = (BitsField*)((char*)p + 8);
    b->f = v;
}
}
