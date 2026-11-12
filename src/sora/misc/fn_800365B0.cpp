#pragma force_active on
extern float lbl_805A1698;
extern float lbl_805A169C;
extern float lbl_805A16A0;
extern float lbl_805A16A4;
struct FnVec2 { float x; float y; };
extern "C" int fn_800365B0(int arg0, FnVec2* v) {
    switch (arg0 & 0xC003) {
    case 0x1: v->y -= lbl_805A1698; break;
    case 0x2: v->x -= lbl_805A1698; break;
    case 0x4000: v->y += lbl_805A1698; break;
    case 0x8000: v->x += lbl_805A1698; break;
    case 0x3: { float y = v->y; float delta = lbl_805A169C; v->y = y - delta; v->x -= delta; break; }
    case 0x8001: { float y = v->y; float delta = lbl_805A169C; v->y = y - delta; v->x += delta; break; }
    case 0x4002: { float y = v->y; float delta = lbl_805A169C; v->y = y + delta; v->x -= delta; break; }
    case 0xC000: { float y = v->y; float delta = lbl_805A169C; v->y = y + delta; v->x += delta; break; }
    default: return 0;
    }
    float x = v->x;
    float highX = lbl_805A16A0;
    float clampedX = (x > highX) ? highX : ((x < lbl_805A16A4) ? lbl_805A16A4 : x);
    float y = v->y;
    float highY = 1.0f;
    v->x = clampedX;
    v->y = (y > highY) ? highY : ((y < lbl_805A16A4) ? lbl_805A16A4 : y);
    return 1;
}