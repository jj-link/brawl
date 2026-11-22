#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};
struct LineData {
    u8 pad[0xf];
    u8 flags;
};
struct CollData {
    u8 pad[0x2c];
    u8 flags;
};
struct Entry {
    LineData* line;
    GroundData* ground;
    CollData* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;
    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    int valid() const {
        int a;
        int b = 0;
        a = 0;
        if (line && ground) a = 1;
        if (a && collision) b = 1;
        return b;
    }
};
struct Seg {
    Vec2f p0;
    Vec2f p1;
    float pad;
};
struct Normal : Vec2f { Normal(const Vec2f& a, const Vec2f& b) : Vec2f(-(a - b).m_y, (a - b).m_x) {} };
struct Owner {
    u8 pad[0x104];
    Entry entry;
};

extern "C" {
extern const float lbl_805A2A40;
extern const float lbl_805A2A44;
void fn_80111968(CollData*, Seg*, LineData*, int);
void fn_800408C4(Seg*, Vec2f*, Vec2f*);
int fn_80113EC0(const Entry*, Entry*);
int fn_80113DF8(const Entry*, Entry*);
void fn_8003DBA8(Vec2f*);
}

static inline float getX(const Vec2f& v) { return v.m_x; }
static inline float getY(const Vec2f& v) { return v.m_y; }

extern "C" int fn_80136610(Owner* owner, Vec3f* pos, Vec3f* out) {
    int ret = 0;
    const Entry* e = &owner->entry;
    Entry cur;
    Entry next;
    Entry* np = &next;
    Seg seg;
    Seg seg2;
    out->m_x = lbl_805A2A40;
    out->m_y = lbl_805A2A44;
    out->m_z = lbl_805A2A40;
    if (!e->valid() || !(e->line->flags & 1)) return 0;
    u32 dir = 0;
    while (true) {
        if (dir == 3) return 0;
        fn_80111968(e->collision, &seg, e->line, 0);
        if (seg.p0.m_x <= pos->m_x && pos->m_x <= seg.p1.m_x) {
            Vec2f p(pos->m_x, pos->m_y);
            fn_800408C4(&seg, &p, &p);
            ret = 1;
            float y = p.m_y;
            float x = p.m_x;
            pos->m_x = x;
            pos->m_y = y;
            pos->m_z = lbl_805A2A40;
            break;
        }
        if (pos->m_x < seg.p0.m_x) {
            dir |= 1;
            if (fn_80113EC0(e, &next)) {
                int enabled;
                if (next.valid() && ((next.ground->flags >> 4) & 1) && ((next.collision->flags >> 7) & 1))
                    enabled = 1;
                else
                    enabled = 0;
                if (enabled && (np->line->flags & 1)) {
                    fn_80111968(next.collision, &seg2, next.line, 0);
                    if (seg2.p0.m_x < seg2.p1.m_x && pos->m_x <= seg2.p1.m_x) {
                        cur = next;
                        e = &cur;
                        continue;
                    }
                }
            }
            float y = seg.p0.m_y;
            float x = seg.p0.m_x;
            pos->m_x = x;
            pos->m_y = y;
            pos->m_z = lbl_805A2A40;
        } else if (seg.p1.m_x < pos->m_x) {
            dir |= 2;
            if (fn_80113DF8(e, &next)) {
                int enabled;
                if (next.valid() && ((next.ground->flags >> 4) & 1) && ((next.collision->flags >> 7) & 1))
                    enabled = 1;
                else
                    enabled = 0;
                if (enabled && (np->line->flags & 1)) {
                    fn_80111968(next.collision, &seg2, next.line, 0);
                    if (seg2.p0.m_x < seg2.p1.m_x && seg2.p0.m_x <= pos->m_x) {
                        cur = next;
                        e = &cur;
                        continue;
                    }
                }
            }
            float y = seg.p1.m_y;
            float x = seg.p1.m_x;
            pos->m_x = x;
            pos->m_y = y;
            pos->m_z = lbl_805A2A40;
        }
        break;
    }
    int valid = 0;
    if (e->line && e->ground && e->collision) valid = 1;
    if (valid) {
        Normal n(seg.p1, seg.p0);
        fn_8003DBA8(&n);
        float y = n.m_y;
        float x = n.m_x;
        out->m_x = x;
        out->m_y = y;
        out->m_z = lbl_805A2A40;
    }
    return ret;
}

