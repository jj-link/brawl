#pragma force_active on
struct fn_27_FE5C8_s {
    unsigned int pad[2];
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" {
void fn_27_FE5C8(void* p, unsigned int v)
{
    ((struct fn_27_FE5C8_s*)p)->f = v;
}
}
