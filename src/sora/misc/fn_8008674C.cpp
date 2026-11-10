#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Rect {
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
};

struct Node {
    Rect rect;
    u8 pad[10];
    s16 flag;
};

struct Obj {
    u8 pad[16];
    Node* node;
};

extern "C" void fn_8011728C(Node*, int, int);

extern "C" void fn_8008674C(Obj* self, const Vec2f* a, const Vec2f* b) {
    register f32 t0, t1, t2, by, ay, bx, ax;
    Rect rect;

    bx = b->m_x;
    ax = a->m_x;
    by = b->m_y;
    ay = a->m_y;
    asm { ps_sub t0, ax, bx }
    asm { ps_sub t1, ax, bx }
    asm { ps_sub t2, ay, by }
    asm { ps_sel t0, t0, bx, ax }
    asm { ps_sel t1, t1, ax, bx }
    asm { ps_sel t2, t2, by, ay }
    rect.left = t0;
    rect.top = t2;
    rect.right = t1;
    asm { ps_sub t0, ay, by }
    asm { ps_sel t0, t0, ay, by }
    rect.bottom = t0;

    self->node->flag = 0;
    __memcpy(&self->node->rect, &rect, sizeof(rect));
    fn_8011728C(self->node, 0, 0);
}
