#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Input {
    Vec2 pos;
    Vec2 dir;
};

struct Output {
    Vec2 normal;
    float d;
};

extern "C" void fn_8003DBA8(Vec2*);

extern "C" Output* fn_800400FC(Output* out, Input* in, int flag) {
    Vec2 v;
    if (flag == 0) {
        float a = in->dir.y;
        float b = in->dir.x;
        v.x = -a;
        v.y = b;
    } else {
        float a = in->dir.x;
        float b = in->dir.y;
        v.x = b;
        v.y = -a;
    }

    fn_8003DBA8(&v);
    float d = v.x * in->pos.x + v.y * in->pos.y;
    out->normal = v;
    out->d = -d;
    return out;
}
