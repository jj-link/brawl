#pragma force_active on

union Vec2 {
    struct { float x, y; };
    unsigned int words[2];
};

union ColorBytes {
    struct { unsigned char r, g, b, a; };
    unsigned int rgba;
};

struct Object {
    unsigned char pad0[0x1C];
    unsigned char flags;
    unsigned char pad1[3];
    Vec2 position;
    unsigned char pad2[0x18];
    ColorBytes color;
    unsigned char pad3[4];
    Vec2 a, b, c;
};

extern ColorBytes lbl_8059FF8C;
extern float lbl_805A13A0;

extern "C" void fn_800428E8(Vec2*, ColorBytes*, int, float);

extern "C" void fn_80011B20(Object* obj) {
    Vec2 points[3];
    points[0] = obj->a;
    points[1] = obj->b;
    points[2] = obj->c;

    points[0].x += obj->position.x;
    points[0].y += obj->position.y;
    points[1].x += obj->position.x;
    points[1].y += obj->position.y;
    points[2].x += obj->position.x;
    points[2].y += obj->position.y;

    if ((obj->flags >> 7) & 1) {
        ColorBytes color;
        color.r = obj->color.r;
        color.g = obj->color.g;
        color.b = obj->color.b;
        color.a = obj->color.a;
        fn_800428E8(points, &color, 1, lbl_805A13A0);
    } else {
        ColorBytes color = lbl_8059FF8C;
        fn_800428E8(points, &color, 0, lbl_805A13A0);
    }
}
