#include <mt/mt_coll2d.h>
#include <types.h>
#pragma force_active on

struct Line {
    Vec2f a;
    Vec2f b;
    int unk;

    Line(const Vec2f& x, const Vec2f& y) : a(x), b(y), unk(0) {}
};

struct Segment {
    Vec2f a;
    Vec2f b;
    int unk[2];

    Segment(void* const& collision, void* line);
};

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    void* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    void clear() {
        line = 0;
        ground = 0;
        collision = 0;
        byte = 0;
        flag = 0;
    }

    void* getFirst() const { return line; }
    bool valid() const { return line && ground && collision; }
    int enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) && ((*(u8*)((char*)collision + 0x2c) >> 7) & 1)) return 1;
        return 0;
    }
};

struct Self {
    u8 pad[0x370];
    clRhombus2D prev;
    u8 pad2[4];
    clRhombus2D current;
};

extern "C" {
extern const float lbl_805A29C8;
extern const float lbl_805A29F0;
extern const float lbl_805A29F4;
void fn_80111968(void*, Segment*, void*, int);
void fn_800429C8(void*, Line*, Line*);
int fn_80042FB4(void*, Segment*);
int fn_80042C74(void*, Segment*);
int fn_800408C4(void*, void*, Vec2f*);
int fn_80115A28(const Entry&, Entry&, float);
void fn_80125250(Self*, int, const Entry&, float);
}

inline Segment::Segment(void* const& collision, void* line) {
    fn_80111968(collision, this, line, 0);
}

extern "C" void fn_8012E9FC(Self& self, const Entry* entry, float* out) {
    Entry next;
    next.clear();
    clRhombus2D* rhombus = &self.current;
    int hit;
    Segment segment(entry->collision, entry->getFirst());

    Line prev(self.prev.m_upPos, self.prev.m_leftPos);
    Line curr(rhombus->m_upPos, rhombus->m_leftPos);

    bool same = 0;
    if (prev.a.m_x == curr.a.m_x && prev.a.m_y == curr.a.m_y)
        same = 1;

    if (same)
        return;

    int same2 = 0;
    if (prev.b.m_x == curr.b.m_x && prev.b.m_y == curr.b.m_y)
        same2 = 1;

    if (!same2) {
        char shape[0x28];
        fn_800429C8(shape, &prev, &curr);

        if (fn_80042FB4(shape, &segment) &&
            fn_80042C74(shape, &segment)) {
            Vec2f point;
            Vec2f delta;
            hit = 0;

            if (segment.a.m_x < curr.a.m_x) {
                Vec2f* endpoint;
                if (fn_800408C4(&curr, (endpoint = &segment.a), &point)) {
                    delta = (*endpoint - point) +
                            Vec2f(lbl_805A29F0, lbl_805A29F4);
                    if (delta.m_y < lbl_805A29F0)
                        hit = 1;
                }
            } else {
                Line& currentLine = curr;
                int use = 0;

                if (segment.b.m_x <= curr.a.m_x) {
                    use = 1;
                } else if (fn_80115A28(*entry, next, curr.a.m_x)) {
                    if (next.enabled()) {
                        fn_80111968(next.collision, &segment, next.line, 0);
                        use = 1;
                    }
                }

                if (use && fn_800408C4(&segment, &currentLine, &point)) {
                    delta = (point - currentLine.a) +
                            Vec2f(lbl_805A29F0, lbl_805A29F4);
                    if (delta.m_y < lbl_805A29F0)
                        hit = 1;
                }
            }

            if (hit) {
                rhombus->move(delta);
                fn_80125250(&self, 7, *entry, *out = lbl_805A29C8);
            }
        }
    }
}
