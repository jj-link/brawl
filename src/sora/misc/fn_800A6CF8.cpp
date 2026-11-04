#include <gf/gf_camera.h>
#pragma force_active on
extern "C" double fn_80400AB8(double);
extern "C" const float lbl_805A2060;
struct State {
    gfCamera* camera;
    char pad[0xB8];
    float fov;
    Vec3f pos;
    float rx, ry, distance, rz;
    Vec3f center, vertical, horizontal;
    float depth;
};
extern "C" void fn_800A6CF8(State* s) {
    gfCamera* c = s->camera;
    s->fov = c->unkD0;
    s->pos = c->m_targetPos;
    s->rx = c->m_rot.m_x;
    s->ry = c->m_rot.m_y;
    float distance = c->unkCC;
    s->distance = distance;
    s->rz = c->m_rot.m_z;
    Vec3f center = c->m_centerPos;
    float aspect = *(float*)((char*)c + 0xE4);
    float height = distance * (float)fn_80400AB8(s->fov * lbl_805A2060);
    float width = height * aspect;
    Vec2f extentCopy;
    Vec2f extent;
    __memcpy(&extent.m_x, &width, sizeof(float));
    __memcpy(&extent.m_y, &height, sizeof(float));
    __memcpy(&extentCopy, &extent, sizeof(Vec2f));

    Vec3f vertical = s->pos;
    Vec3f horizontal = s->pos;
    Vec3f base = s->pos;
    vertical.m_x += extentCopy.m_y;
    horizontal.m_x += extentCopy.m_x;
    s->center = center;
    s->vertical = vertical;
    s->horizontal = horizontal;
    s->depth = c->unkCC;
}
