#pragma force_active on
#include <mt/mt_vector.h>

struct Words { int x, y; };

struct PointOwner {
    char pad[0x1c];
    Vec2f position;
};
struct Context {
    char pad[0x18];
    PointOwner* owner;
};
struct Candidate {
    unsigned char active : 8;
    unsigned int kind : 8;
    unsigned int unused : 16;
    int id;
    Vec2f position;
};

inline float squareLength(Vec2f value) {
    Vec2f copy = value;
    return value.lengthSq();
}

extern "C" void fn_80120500(Context* ctx, Candidate* out, int id, int kind, Vec2f* pos) {
    if (out->active == 0) {
        out->active = 1;
        out->kind = kind;
        out->position.m_x = pos->m_x;
        out->position.m_y = pos->m_y;
        out->id = id;
        return;
    }
    Vec2f next;
    Vec2f nextCopy;
    Vec2f prev;
    Vec2f prevCopy;
    Vec2f nextTemp;
    Vec2f prevTemp;
    nextTemp.m_x = ctx->owner->position.m_x - pos->m_x;
    nextTemp.m_y = ctx->owner->position.m_y - pos->m_y;
    prevTemp.m_x = ctx->owner->position.m_x - out->position.m_x;
    prevTemp.m_y = ctx->owner->position.m_y - out->position.m_y;
    *(Words*)&next = *(Words*)&nextTemp;
    *(Words*)&prev = *(Words*)&prevTemp;
    float nextSq = next.lengthSq();
    float prevSq = prev.lengthSq();
    *(Words*)&nextCopy = *(Words*)&nextTemp;
    *(Words*)&prevCopy = *(Words*)&prevTemp;
    if (kind == 1 && nextSq < prevSq) {
        out->kind = kind;
        out->position.m_x = pos->m_x;
        out->position.m_y = pos->m_y;
        out->id = id;
    } else if (kind == 0 && nextSq < prevSq) {
        out->kind = kind;
        out->position.m_x = pos->m_x;
        out->position.m_y = pos->m_y;
        out->id = id;
    }
}
