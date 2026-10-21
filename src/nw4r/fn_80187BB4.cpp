#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Rect {
    float x1, x2, y1, y2;
};

struct Input {
    int unk0;
    int first;
    char pad[0x14];
    int second;
};

extern "C" void fn_8018ACEC(Vec2*, int, int);

extern "C" Rect fn_80187BB4(void*, int mode, Input* input) {
    Rect result = {};

    switch (mode) {
    case 1: {
        Vec2 point;
        fn_8018ACEC(&point, input->first, 0);
        result.x1 = point.x;
        result.y1 = point.y;
        result.x2 = point.x;
        result.y2 = point.y;
        break;
    }
    case 4:
    case 8: {
        Vec2 point;
        fn_8018ACEC(&point, input->first, 0);
        result.x1 = point.x;
        result.y1 = point.y;

        Vec2 other;
        fn_8018ACEC(&other, input->second, 0);
        point = other;
        result.x2 = point.x;
        result.y2 = point.y;
        break;
    }
    }

    return result;
}
