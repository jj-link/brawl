#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct
{
    float x;
    float y;
} Vec2;

extern "C" u64 fn_113_1E58C(Vec2 *v)
{
    union
    {
        struct
        {
            float x;
            float y;
        } f;
        struct
        {
            u32 a;
            u32 b;
        } w;
        u64 q;
    } out;

    out.f.x = -v->x;
    out.f.y = -v->y;
    return out.q;
}
