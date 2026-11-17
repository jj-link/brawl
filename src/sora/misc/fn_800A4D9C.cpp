#include <types.h>
#include <cm/cm_camera_controller.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Box {
    Vec2f min;
    Vec2f max;
};
struct Object {
    char pad[0x98];
    f32 width;
    f32 height;
};

extern "C" {
int fn_80041978(Box*, Box*);
void fn_800A46B4(Object*, Box*, Vec2f*, Vec2f*);
void* __memcpy(void*, const void*, unsigned long);
extern f32 lbl_805A1FA0;
}

inline void makeEdge(Box* edge, const Vec2f& min, const Vec2f& max) {
    __memcpy(&edge->min, &min, sizeof(Vec2f));
    __memcpy(&edge->max, &max, sizeof(Vec2f));
}

extern "C" void fn_800A4D9C(Object* self, Vec2f* arg) {
    Box edges[4];
    Box box;
    Vec2f pos;
    Vec2f half;

    f32 hx = lbl_805A1FA0 * self->width;
    f32 hy = lbl_805A1FA0 * self->height;
    f32 x = arg->m_x;
    f32 y = arg->m_y;
    pos.m_x = x;
    pos.m_y = y;
    f32 x0 = x - hx;
    f32 y0 = y - hy;
    f32 y1 = y + hy;
    f32 x1 = x + hx;
    box.min.m_x = x0;
    box.min.m_y = y0;
    box.max.m_x = x1;
    box.max.m_y = y1;

    CameraController* cam = CameraController::getInstance();
    Rect2D* r = reinterpret_cast<Rect2D*>(cam->_328);

    makeEdge(&edges[0], Vec2f(r->m_left, r->m_up), Vec2f(r->m_left, r->m_down));
    makeEdge(&edges[1], Vec2f(r->m_left, r->m_down), Vec2f(r->m_right, r->m_down));
    makeEdge(&edges[2], Vec2f(r->m_right, r->m_down), Vec2f(r->m_right, r->m_up));
    makeEdge(&edges[3], Vec2f(r->m_right, r->m_up), Vec2f(r->m_left, r->m_up));

    half.m_x = hx;
    half.m_y = hy;

    for (int i = 0; i < 4; i++) {
        if (fn_80041978(&box, &edges[i]) != 0) {
            fn_800A46B4(self, &edges[i], &pos, &half);
        }
    }

    if (self->width > r->m_right - r->m_left) {
        pos.m_x = r->m_left + lbl_805A1FA0 * (r->m_right - r->m_left);
    }
    if (self->height > r->m_up - r->m_down) {
        pos.m_y = r->m_down + lbl_805A1FA0 * (r->m_up - r->m_down);
    }
    arg->m_x = pos.m_x;
    arg->m_y = pos.m_y;
}
