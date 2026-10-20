#pragma force_active on
struct Float2 {
    float pad[2];
    float x;
    float y;
};

extern "C" float fn_104_12870(Float2 *p)
{
    return p->x * p->y;
}
