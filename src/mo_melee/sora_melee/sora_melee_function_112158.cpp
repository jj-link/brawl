#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Obj {
    unsigned char pad[0x78];
    void *arg;
    Vec2 first;
    Vec2 second;
};

extern "C" void fn_27_112158(Obj **p, void *arg, const Vec2 *a, const Vec2 *b)
{
    (*p)->arg = arg;
    (*p)->first.x = a->x;
    (*p)->first.y = a->y;
    (*p)->second.x = b->x;
    (*p)->second.y = b->y;
}
