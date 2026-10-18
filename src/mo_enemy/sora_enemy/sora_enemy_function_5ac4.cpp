#pragma force_active on
struct V3 {
    float x, y, z;
};

extern "C" {
extern V3* fn_41_5AC4(V3* v, float x, float y, float z);
}

V3* fn_41_5AC4(V3* v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}
