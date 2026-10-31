#pragma force_active on

typedef unsigned short u16;
typedef unsigned int u32;

struct Vec3 { float x, y, z; };
struct Vec2 {
    float x, y;
    inline void set(const Vec3* p) {
        float a, b;
        b = p->y;
        a = p->x;
        x = a;
        y = b;
    }
};
struct Box { Vec2 min, max; };
struct Polygon {
    u16 count;
    u16 pad;
    Vec3* points;
    Vec3 min, max;
    char rest[0x20];
};
struct Mesh { u32 count; Polygon* polygons; };
struct Object { char pad[0x98]; float width, height; Mesh* mesh; };

extern "C" int fn_80041D64(Box*, Box*);
extern "C" int fn_80041978(Box*, Box*);
extern "C" void fn_800A46B4(Object*, Box*, Vec2*, Vec2*);
extern float lbl_805A1FA0;
extern float lbl_805A1FCC;

inline void makeBox(Box* box, float left, float bottom, float right, float top) {
    float margin = lbl_805A1FCC;
    float bottomFinal = bottom;
    float leftFinal = left - margin;
    box->min.y = bottomFinal;
    box->min.x = leftFinal;
    float topFinal = margin + top;
    box->max.x = margin + right;
    box->max.y = topFinal;
}

extern "C" void fn_800A4BE4(Object* self, Vec2* arg) {
    Box box;
    Box other;
    Box edge;
    Vec2 pos;
    Vec2 half;
    float x, y;
    float hx = lbl_805A1FA0 * self->width;
    float hy = lbl_805A1FA0 * self->height;
    x = arg->x;
    y = arg->y;
    pos.x = x;
    pos.y = y;
    makeBox(&box, x - hx, (y - hy) - lbl_805A1FCC, x + hx, y + hy);
    {
        Polygon* poly;
        int outerOffset;
        int innerOffset;
        Mesh* mesh;
        u32 i;
        u32 j;
        mesh = self->mesh;
        if (mesh) {
            half.x = hx;
            half.y = hy;
            i = 0;
            outerOffset = 0;
            for (; i < mesh->count; outerOffset += 0x40, ++i) {
                poly = (Polygon*)((char*)mesh->polygons + outerOffset);
                other.min.set(&poly->min);
                other.max.set(&poly->max);
                if (fn_80041D64(&box, &other)) {
                    j = 0;
                    innerOffset = 0;
                    for (; j < (u16)*(short*)poly; innerOffset += 0xC, ++j) {
                        if (j == (u32)(poly->count - 1)) {
                            Vec3* p;
                            Vec3* items = poly->points;
                            p = (Vec3*)((char*)items + innerOffset);
                            edge.min.set(p);
                            edge.max.set(items);
                        } else {
                            Vec3* p = (Vec3*)((char*)poly->points + innerOffset);
                            edge.min.set(p);
                            edge.max.set(p + 1);
                        }
                        if (fn_80041978(&box, &edge))
                            fn_800A46B4(self, &edge, &pos, &half);
                    }
                }
            }
            arg->x = pos.x;
            arg->y = pos.y;
        }
    }
}
