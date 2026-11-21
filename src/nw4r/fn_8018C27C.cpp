#include <types.h>
#pragma force_active on
#pragma optimize_for_size on
struct Vec2 { float x, y; };
struct Item { Vec2 a, b, c, d; };
struct State { u8 limit, index; Item* data; };
extern "C" {
extern signed char lbl_805A0530;
extern float lbl_805A3170, lbl_805A3174;
extern Item lbl_804A4498;
void fn_8018C27C(State* self, u8 target) {
    if (!self->data) return;
    if (target > self->limit) return;
    if (!lbl_805A0530) {
        lbl_804A4498.a.x = lbl_805A3170;
        lbl_804A4498.a.y = lbl_805A3170;
        lbl_804A4498.b.x = lbl_805A3174;
        lbl_804A4498.b.y = lbl_805A3170;
        lbl_804A4498.c.x = lbl_805A3170;
        lbl_804A4498.c.y = lbl_805A3174;
        lbl_804A4498.d.x = lbl_805A3174;
        lbl_804A4498.d.y = lbl_805A3174;
        lbl_805A0530 = 1;
    }
    int offset = self->index * 32;
    float a7, a6, a5, a4, a3, a2, a1, a0;
    a0 = lbl_804A4498.a.x;
    a1 = lbl_804A4498.a.y;
    a2 = lbl_804A4498.b.x;
    a3 = lbl_804A4498.b.y;
    a4 = lbl_804A4498.c.x;
    a5 = lbl_804A4498.c.y;
    a6 = lbl_804A4498.d.x;
    a7 = lbl_804A4498.d.y;
    for (int i = self->index; i < target; ++i, offset += 32) {
        Vec2* p = (Vec2*)((char*)self->data + offset);
        p->x = a0; p->y = a1;
        p = (Vec2*)((char*)self->data + offset + 8);
        p->x = a2; p->y = a3;
        p = (Vec2*)((char*)self->data + offset + 16);
        p->x = a4; p->y = a5;
        p = (Vec2*)((char*)self->data + offset + 24);
        p->x = a6; p->y = a7;
    }
    self->index = target;
}
}