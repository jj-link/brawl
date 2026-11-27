#include <types.h>
#include <gr/collision/gr_collision.h>
#include <mt/mt_coll2d.h>

#pragma force_active on

class Class_8042EA48 {
public:
    virtual void fn_8005C534();
    virtual void fn_8005C2B0();
    virtual void fn_8005C20C();
    virtual void fn_8005C1BC();
    virtual void fn_8005C198();
    virtual void fn_8005C17C();
    virtual void fn_8005C160();
    virtual void fn_8005C0BC();
    virtual Vec2f fn_8005C06C();
    virtual Vec2f fn_8005C048();
    virtual void fn_8005C02C();
    virtual void fn_8005C010();
    virtual Vec2f fn_8005BF6C();
    virtual void fn_8005BF1C();
    virtual void fn_8005BEF8();
    virtual void fn_8005BEDC();
    virtual void fn_8005BEC0();
    virtual void fn_8005BE1C();
    virtual void fn_8005BDCC();
    virtual void fn_8005BDA8();
    virtual void fn_8005BD8C(Vec2f*, const Vec2f*, const Vec2f*);
};

class Class_804645B0 {
public:
    virtual void fn_8015D358();
    virtual void fn_8015CF94();
    virtual void fn_8015D00C();
    virtual void fn_8015D05C();
    virtual void fn_8015D0E4();
    virtual void fn_8015CC00();
    virtual void fn_8015CC04();
    virtual void fn_8015D350();
    virtual Vec2f fn_8015D338();
    virtual Vec2f fn_8015D328();
    virtual void fn_8015D320();
    virtual void fn_8015D310();
    virtual Vec2f fn_8015D308();
    virtual void fn_8015D300();
    virtual void fn_8015D340();
    virtual void fn_8015D294();
    virtual void fn_8015D29C();
    virtual void fn_8015D2A4();
    virtual void fn_8015D330();
    virtual void fn_8015D318();
    virtual void fn_8015D348(Vec2f*, const Vec2f*, const Vec2f*);
};

struct GroundData {
    char pad[0x54];
    u8 flags;
};

struct Entry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 type;
    u8 flag : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), type(0), flag(0) {}

    int valid() const {
        return line && ground && collision;
    }

    int active() const {
        if (valid() && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            return 1;
        return 0;
    }

    int equals(const Entry& e) const {
        int r = 0;
        if (line == e.line) r = 1;
        return r;
    }

    int upper() const {
        return (*(u8*)((char*)line + 0xf) >> 1) & 1;
    }
};

struct Owner {
    char pad0[0x75];
    u8 flags;
    char pad1[0xd4 - 0x76];
    Entry current;
};

struct List {
    char pad[0x1a];
    u16 count;
    Entry* entries;
};

inline Entry* getEntry(List* list, u32 offset) {
    return (Entry*)((char*)list->entries + offset);
}

struct Object {
    char pad0[0xd];
    u8 flags;
    char pad1[2];
    u8 mask;
    char pad2[7];
    Owner* owner;
    List* list;
    char pad3[0x34 - 0x20];
    u8 state;
    char pad4[3];
    float value;
    Entry current;
    char pad5[0x224 - 0x4c];
    Entry previous;
    char pad6[0x2bc - 0x234];
    Class_8042EA48* position;
    char pad7[4];
    Class_804645B0* bounds;
    char pad8[3];
    union {
        u8 status;
        struct {
            u8 hi : 2;
            u8 hit : 1;
            u8 lo : 5;
        } statusBits;
    };
    char pad9[0x2e8 - 0x2cc];
    float minY;

    void land(float v, const Entry& r) {
        statusBits.hit = 1;
        state = 0;
        value = v;
        current = r;
        flags |= 1;
    }

    void setRecord(u8 mode, float v, const Entry& r) {
        state = mode;
        value = v;
        current = r;
    }
};

extern "C" {
int fn_800408C4(clSegment2D*, const Vec2f*, Vec2f*);
int fn_80114A60(const Entry*, const Entry*);
int fn_80137074(Owner*, const Entry*);
extern float lbl_805A2960;
extern const float lbl_805A297C;
extern float lbl_805A2984;
extern float lbl_805A2994;
}

inline u16 collisionMask(u8 flags) {
    u16 mask = 0;
    if (flags & 1) mask |= 2;
    if (flags & 8) mask |= 1;
    if (flags & 2) mask |= 4;
    if (flags & 4) mask |= 8;
    return mask;
}

extern "C" void fn_80123270(Object* self) {
    self->status = 0;
    u16 mask = collisionMask(self->mask);
    u32 offset;
    Entry* e;
    u16 count = self->list->count;

    float delta = self->bounds->fn_8015D308().m_y -
                  self->bounds->fn_8015D328().m_y;
    Vec2f original;
    Vec2f::copy(original, self->position->fn_8005C048());
    Vec2f point;
    Vec2f::copy(point, original + Vec2f(lbl_805A2960, delta));
    float ignored = self->position->fn_8005C06C().m_y;

    float epsilon;
    float bestY;
    float limit;
    float x;
    limit = lbl_805A2984 + original.m_y;
    bestY = point.m_y;
    x = point.m_x;

    Entry entry;
    clSegment2D segment;
    Vec2f hit;
    int hasPrevious = 0;
    if (self->previous.valid()) hasPrevious = 1;
    epsilon = lbl_805A2994;
    Entry* best = 0;

    {
        u32 i = 0;
        offset = 0;
        for (; i < count; offset += 0x10, ++i) {
            e = (Entry*)((char*)self->list->entries + offset);
            entry = *e;
            if (entry.active() && (*(u16*)((char*)entry.line + 0xe) & mask) &&
                entry.type == 0 && entry.upper()) {
                entry.collision->getSegment(&segment, entry.line);
                if (segment.m_p1Pos.m_x <= x &&
                    x <= segment.m_p0Pos.m_x &&
                    fn_800408C4(&segment, &point, &hit)) {
                    float y = hit.m_y - epsilon;
                    if (limit < y && y < bestY) {
                        bestY = y;
                        best = e;
                    }
                }
            }
        }
    }

    {
        u32 i = 0;
        offset = 0;
        for (; i < count; offset += 0x10, ++i) {
            e = getEntry(self->list, offset);
            if ((*(u8*)((char*)e->line + 0xf) & 1) && e->active() &&
                (*(u16*)((char*)e->line + 0xe) & mask)) {
                if (hasPrevious && (e->equals(self->previous) ||
                    fn_80114A60(&self->previous, e)))
                    continue;
                e->collision->getSegment(&segment, e->line);
                if (segment.m_p0Pos.m_x <= x &&
                    x <= segment.m_p1Pos.m_x &&
                    fn_800408C4(&segment, &point, &hit) &&
                    limit < hit.m_y && hit.m_y < bestY)
                    fn_80137074(self->owner, e);
            }
        }
    }

    if (best) {
        point.m_x = x;
        point.m_y = bestY;
        Vec2f middle;
        Vec2f::copy(middle, (point + original) * lbl_805A297C);
        self->position->fn_8005BD8C(&middle, &point, &original);
        if (middle.m_y < self->minY) self->minY = middle.m_y;
        self->land(lbl_805A2960, *best);
        self->owner->current = *best;
        self->owner->flags |= 0x40;
    }
}
