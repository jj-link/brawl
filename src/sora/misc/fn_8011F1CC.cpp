// The closest checked candidate matched 98.6%, with 22 differing lines.
#include <gr/collision/gr_collision.h>
#include <mt/mt_coll2d.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(const Vec2f&);
    virtual u64 slot8();
    virtual u64 slot9();
    virtual u64 slot10();
    virtual u64 slot11();
    virtual u64 slot12();
    virtual void slot13();
    virtual void slot14(Object_vptr_0*);
    virtual f32 slot15();
};

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Contact {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 index;
    union {
        u8 flags;
        struct { u8 first : 1; u8 rest : 7; } bits;
    };

    void clear() {
        line = 0;
        ground = 0;
        collision = 0;
        index = 0;
        bits.first = 0;
    }

    bool valid() const {
        return line && ground && collision;
    }

    bool enabled() const {
        if (valid() && ((ground->flags >> 4) & 1) &&
            ((reinterpret_cast<const u8*>(collision)[0x2c] >> 7) & 1))
            return true;
        return false;
    }
};

struct Candidate {
    u8 index;
    f32 distance;
    Contact contact;

    void resetFields() {
        index = 0xff;
        contact.line = 0;
        contact.ground = 0;
        contact.collision = 0;
        contact.index = 0;
    }
};

struct State {
    u8 pad00[0x60];
    Object_vptr_0* shape;
    u8 pad64[8];
    s32 kind;
    u8 pad70;
    u8 flags71;
    u8 pad72[3];
    u8 flags75;
    u8 pad76[0x1e];
    f32 x94;
    f32 y98;
    u8 pad9c[0x38];
    Contact contacts[8];
};

struct Group {
    u8 pad[0x1a];
    u16 count;
};

struct Object_vptr_32c_base {
    u8 pad00[8];
    f32 distance;
    u8 flags;
    u8 contacts;
    u8 direction;
    u8 mode;
    u8 pad10[8];
    State* state;
    Group* group;
    u8 pad20[0x14];
    Candidate candidates[9];
    u8 pad10c[0x1b0];
    Object_vptr_0* shape;
    Object_vptr_0* result;
    Object_vptr_0* next;
    u8 pad2c8[8];
    s32 step;
    u8 pad2d4[0x58];
};

class Object_vptr_32c : public Object_vptr_32c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};

struct Segment {
    clSegment2D segment;
    s32 kind;
};

extern "C" {
extern const f32 lbl_805A295C;
extern const f32 lbl_805A2994;
void fn_80117B94(Object_vptr_32c*, clAABBox2D*);
void fn_80111968(grCollision*, Segment*, grCollisionLine*, s32);
s32 fn_80113DF8(const Contact*, Contact*);
s32 fn_80113EC0(const Contact*, Contact*);
s32 fn_80119AD4(Object_vptr_32c*, const Contact*, Contact*);
void fn_80119D1C(const Contact*, const Vec2f*, Vec2f*, Vec2f*);
void fn_8011A758(Object_vptr_32c*, const Contact*);
s32 fn_80124718(Object_vptr_32c*);
void fn_80122E7C(Object_vptr_32c*);
void fn_801221D4(Object_vptr_32c*);
void fn_80133F24(State*);
void fn_80134468(State*, s32);
void fn_80118294(Object_vptr_32c*, clAABBox2D*);
}

static inline int saveContacts(Object_vptr_32c* self) {
    int result = (self->state->flags75 >> 7) & 1;
    if (self->contacts) {
        for (int i = 0; i < 8; ++i) {
            if (self->candidates[i].contact.enabled())
                self->state->contacts[i] = self->candidates[i].contact;
        }
    }
    return result;
}

struct CollisionWork {
    Vec2f rightEndpoint;
    Vec2f leftEndpoint;
    Vec2f extra;
    Vec2f projected;
    clSegment2D segment;
    Contact neighbor;
    Contact replacement;
    Contact current;
    clAABBox2D rect;
    Segment nextSegment;
    Segment currentSegment;
    Segment previousSegment;
};

extern "C" int fn_8011F1CC(Object_vptr_32c* self) {
    State* state;
    CollisionWork work;
    u64 initialPos;
    Vec2f projectionInput;
    Vec2f centerY;
    Vec2f bottom;
    Vec2f centerLeft;
    Vec2f left;
    Vec2f right;
    Vec2f centerX;
    Vec2f loopPos;
    Vec2f target;
    Vec2f rawPos;
    Vec2f previousPos;
    Vec2f endpoint;
    self->step = 1;
    work.current.clear();
    work.replacement.clear();
    Candidate* const candidates = self->candidates;
    f32* d1 = &candidates[1].distance;
    f32* d2 = &candidates[2].distance;
    f32* d3 = &candidates[3].distance;
    f32* d4 = &candidates[4].distance;
    f32* d5 = &candidates[5].distance;
    f32* d6 = &candidates[6].distance;
    f32* d7 = &candidates[7].distance;
    Contact* contact = &work.current;

    self->distance = lbl_805A295C;
    candidates[0].distance = lbl_805A295C;
    *d1 = lbl_805A295C;
    *d2 = lbl_805A295C;
    *d3 = lbl_805A295C;
    *d4 = lbl_805A295C;
    *d5 = lbl_805A295C;
    *d6 = lbl_805A295C;
    *d7 = lbl_805A295C;
    candidates[8].distance = lbl_805A295C;
    candidates[8].resetFields();

    fn_80117B94(self, &work.rect);

    {
        initialPos = self->shape->slot12();
        State* owner = self->state;
        const Vec2f& pos = reinterpret_cast<const Vec2f&>(initialPos);
        f32 y;
        f32 x;
        x = pos.m_x;
        y = pos.m_y;
        owner->x94 = x;
        owner->y98 = y;
    }

    *contact = candidates[0].contact;
    if (self->state->flags71 & 1) {
        *reinterpret_cast<u64*>(&projectionInput) = self->shape->slot12();
        fn_80119D1C(contact, &projectionInput, &work.projected, &work.extra);
        self->shape->slot7(work.projected);
    }

    state = self->state;
    self->mode = 0xf6;
    if ((state->kind >> 24) == 1 && (reinterpret_cast<u8*>(&state->kind)[1] & 1)) {
        state->shape->slot14(self->shape);
        int result = saveContacts(self);
        self->flags |= 0x80;
        return result;
    }

    if (state->contacts[0].enabled()) {
        f32 height = self->result->slot15();
        u64 raw = self->shape->slot12();
        u32 lo = static_cast<u32>(raw);
        u32 hi = static_cast<u32>(raw >> 32);
        reinterpret_cast<u32*>(&rawPos)[1] = lo;
        grCollisionLine* line = state->contacts[0].line;
        reinterpret_cast<u32*>(&previousPos)[1] = lo;
        reinterpret_cast<u32*>(&rawPos)[0] = hi;
        reinterpret_cast<u32*>(&previousPos)[0] = hi;
        fn_80111968(state->contacts[0].collision, &work.previousSegment, line, 0);

        register f32 newTop;
        register f32 top;
        register f32 bottom;
        register f32 limit;
        register f32 base;
        register f32 high;
        register f32 low;
        register f32 y0;
        limit = work.previousSegment.segment.m_p1Pos.m_y;
        y0 = work.previousSegment.segment.m_p0Pos.m_y;
        asm { ps_sub low, y0, limit }
        top = work.rect.m_unk4;
        asm { ps_sub high, y0, limit }
        bottom = work.rect.m_unk2;
        base = previousPos.m_y - height;
        asm { ps_sel low, low, limit, y0 }
        asm { ps_sel high, high, y0, limit }
        asm { ps_sub limit, low, base }
        asm { ps_sub newTop, top, high }
        asm { ps_sel limit, limit, base, low }
        asm { ps_sel newTop, newTop, top, high }
        asm { ps_sub top, bottom, limit }
        work.rect.m_unk4 = newTop;
        asm { ps_sel top, top, limit, bottom }
        work.rect.m_unk2 = top;
    }

    {
        u64 bottomRaw = self->shape->slot9();
        u32* bottomWords = reinterpret_cast<u32*>(&bottom);
        bottomWords[0] = static_cast<u32>(bottomRaw >> 32);
        Object_vptr_0* bottomShape = self->shape;
        bottomWords[1] = static_cast<u32>(bottomRaw);
        u64 centerYRaw = bottomShape->slot8();
        u32* centerYWords = reinterpret_cast<u32*>(&centerY);
        centerYWords[0] = static_cast<u32>(centerYRaw >> 32);
        centerYWords[1] = static_cast<u32>(centerYRaw);
        work.rect.m_unk2 -= centerY.m_y - bottom.m_y;

        u64 leftRaw = self->shape->slot10();
        u32* leftWords = reinterpret_cast<u32*>(&left);
        leftWords[0] = static_cast<u32>(leftRaw >> 32);
        Object_vptr_0* leftShape = self->shape;
        leftWords[1] = static_cast<u32>(leftRaw);
        u64 centerLeftRaw = leftShape->slot8();
        u32* centerLeftWords = reinterpret_cast<u32*>(&centerLeft);
        centerLeftWords[0] = static_cast<u32>(centerLeftRaw >> 32);
        centerLeftWords[1] = static_cast<u32>(centerLeftRaw);
        work.rect.m_unk1 -= centerLeft.m_x - left.m_x;

        u64 centerXRaw = self->shape->slot8();
        u32* centerXWords = reinterpret_cast<u32*>(&centerX);
        centerXWords[0] = static_cast<u32>(centerXRaw >> 32);
        Object_vptr_0* centerXShape = self->shape;
        centerXWords[1] = static_cast<u32>(centerXRaw);
        u64 rightRaw = centerXShape->slot11();
        u32* rightWords = reinterpret_cast<u32*>(&right);
        rightWords[0] = static_cast<u32>(rightRaw >> 32);
        rightWords[1] = static_cast<u32>(rightRaw);
        work.rect.m_unk3 += right.m_x - centerX.m_x;
    }

    fn_80118294(self, &work.rect);

    f32 distance = lbl_805A295C;
    for (;;) {
        *reinterpret_cast<u64*>(&loopPos) = self->next->slot12();
        s32 outside = 0;
        fn_80111968(contact->collision, &work.currentSegment, contact->line, 0);
        register f32 x1;
        register f32 minX;
        register f32 maxX;
        register f32 x0;
        x1 = work.currentSegment.segment.m_p1Pos.m_x;
        x0 = work.currentSegment.segment.m_p0Pos.m_x;
        u8 direction = self->direction;
        asm { ps_sub maxX, x0, x1 }
        asm { ps_sub minX, x0, x1 }
        asm { ps_sel maxX, maxX, x0, x1 }
        asm { ps_sel minX, minX, x1, x0 }
        if ((direction & 2) && loopPos.m_x > maxX)
            outside = 1;
        else if ((direction & 1) && loopPos.m_x < minX)
            outside = 1;

        s32 found = 0;
        if (outside)
            found = fn_80119AD4(self, contact, &work.replacement);
        fn_8011A758(self, contact);

        if (self->group->count ? fn_80124718(self) : 0) {
            self->result->slot14(self->shape);
            self->flags |= 0x80;
            break;
        } else if (outside) {
            if (found) {
                *contact = work.replacement;
                if (candidates[0].distance >= distance) {
                    candidates[0].index = 0;
                    candidates[0].distance = distance;
                    candidates[0].contact = *contact;
                    self->contacts |= 1;
                    if (candidates[8].distance >= distance) {
                        candidates[8].index = 0;
                        candidates[8].distance = distance;
                        __memcpy(&candidates[8].contact, &candidates[0].contact, sizeof(Contact));
                    }
                }
                fn_80111968(contact->collision, &work.nextSegment, contact->line, 0);
                const Vec2f& first = work.nextSegment.segment.m_p0Pos;
                const Vec2f& last = work.nextSegment.segment.m_p1Pos;
                if (self->direction & 2) {
                    if (first.m_x < last.m_x) {
                        endpoint.m_x = work.nextSegment.segment.m_p0Pos.m_x;
                        endpoint.m_y = first.m_y;
                    } else {
                        endpoint.m_x = work.nextSegment.segment.m_p1Pos.m_x;
                        endpoint.m_y = last.m_y;
                    }
                } else {
                    if (first.m_x < last.m_x) {
                        endpoint.m_x = work.nextSegment.segment.m_p1Pos.m_x;
                        endpoint.m_y = last.m_y;
                    } else {
                        endpoint.m_x = work.nextSegment.segment.m_p0Pos.m_x;
                        endpoint.m_y = first.m_y;
                    }
                }
                __memcpy(&target, &endpoint, sizeof(Vec2f));
                self->shape->slot7(target);
                continue;
            }

            fn_80133F24(self->state);
            fn_80134468(self->state, 0);
            bool validNeighbor = false;
            work.neighbor.clear();
            contact->collision->getSegment(&work.segment, contact->line);

            if (self->direction & 2) {
                if (fn_80113EC0(contact, &work.neighbor)) {
                    if (*reinterpret_cast<const u32*>(&work.neighbor.line) && work.neighbor.ground && work.neighbor.collision)
                        validNeighbor = true;
                    if (validNeighbor && ((reinterpret_cast<const u8*>(work.neighbor.line)[0xf] >> 3) & 1)) {
                        __memcpy(&work.leftEndpoint, &work.segment.m_p0Pos, sizeof(Vec2f));
                        work.leftEndpoint.m_x -= lbl_805A2994;
                        self->shape->slot7(work.leftEndpoint);
                        candidates[0].contact = *contact;
                        self->flags |= 0x80;
                        break;
                    }
                }
            } else {
                if (fn_80113DF8(contact, &work.neighbor)) {
                    if (*reinterpret_cast<const u32*>(&work.neighbor.line) && work.neighbor.ground && work.neighbor.collision)
                        validNeighbor = true;
                    if (validNeighbor && ((reinterpret_cast<const u8*>(work.neighbor.line)[0xf] >> 2) & 1)) {
                        __memcpy(&work.rightEndpoint, &work.segment.m_p1Pos, sizeof(Vec2f));
                        work.rightEndpoint.m_x += lbl_805A2994;
                        self->shape->slot7(work.rightEndpoint);
                        candidates[0].contact = *contact;
                        self->flags |= 0x80;
                        break;
                    }
                }
            }

            self->contacts = 0;
            candidates[0].distance = lbl_805A295C;
            candidates[0].resetFields();
            *d1 = lbl_805A295C;
            candidates[1].resetFields();
            *d2 = lbl_805A295C;
            candidates[2].resetFields();
            *d3 = lbl_805A295C;
            candidates[3].resetFields();
            *d4 = lbl_805A295C;
            candidates[4].resetFields();
            *d5 = lbl_805A295C;
            candidates[5].resetFields();
            *d6 = lbl_805A295C;
            candidates[6].resetFields();
            *d7 = lbl_805A295C;
            candidates[7].resetFields();
            candidates[8].distance = lbl_805A295C;
            candidates[8].resetFields();
            break;
        } else {
            self->flags |= 0x80;
            self->shape->slot14(self->result);
            break;
        }
    }

    if (!((self->flags >> 7) & 1))
        self->result->slot14(self->next);
    self->slot3();
    fn_80122E7C(self);
    fn_801221D4(self);
    self->mode |= 9;
    self->state->shape->slot14(self->shape);
    return saveContacts(self);
}
