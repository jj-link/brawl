#pragma force_active on
struct Float2 {
    float pad[2];
    float x;
    float y;
};

extern "C" float fn_119_1345C(Float2 *v)
{
    return v->x * v->y;
}
