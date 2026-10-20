#pragma force_active on
typedef struct {
    float x;
    float y;
} Vec2f;

typedef struct {
    Vec2f pts[16];
    unsigned char pad[0x40];
    int idx;
} Obj;

extern "C" Vec2f fn_27_22009C(Obj* self, int i)
{
    Vec2f tmp;
    if (i < 0) {
        i = 0;
    } else if (i >= 16) {
        i = 15;
    }
    int j = self->idx - i;
    if (j < 0) {
        j += 16;
    }
    if (&tmp != 0) {
        tmp.x = self->pts[j].x;
        tmp.y = self->pts[j].y;
    }
    return tmp;
}
