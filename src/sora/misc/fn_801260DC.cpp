#include <gr/collision/gr_collision.h>
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
    virtual void slot7();
    virtual Vec2f slot8();
    virtual Vec2f slot9();
    virtual Vec2f slot10();
    virtual Vec2f slot11();
    virtual Vec2f slot12();
};

struct GroundData { u8 pad[0x54]; u8 flags; };
struct Entry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 byte;
    u8 flag:1;
    u8 rest:7;
    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    bool valid() const { return line && ground && collision; }
    int enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            return 1;
        return 0;
    }
    bool same(grCollisionLine* other) const {
        bool result = false;
        if (line == other) result = true;
        return result;
    }
};
struct Owner { u8 pad[8]; signed int kind:8; unsigned int unused:24; };
struct Group {
    float left,bottom,right,top;
    u8 pad[0xa];
    u16 count;
    Entry* entries;
};
struct Context {
    u8 pad0[0x18];
    Owner* owner;
    Group* group;
    u8 pad20[0x64];
    Entry attached;
    u8 pad94[0x228];
    Object_vptr_0* object;
    u8 pad2c0[0x24];
    float x;
    u8 pad2e8[4];
    Vec2f up,down,left,right;
    u8 pad30c[0x10];
    Entry selected;
    u8 pad32c[0x4c];
    Vec2f topPos,centerPos,leftPos,rightPos;
};

extern "C" {
u16 fn_80121214(void*);
int fn_80137114(Owner*, Entry*);
int fn_800408C4(clSegment2D*,clSegment2D*,Vec2f*);
int fn_8004094C(clSegment2D*,Vec2f*,Vec2f*);
int fn_80113EC0(Entry*,Entry*);
int fn_80113F88(Entry*,Entry*);
int fn_80113DF8(Entry*,Entry*);
int fn_80114024(Entry*,Entry*);
}
extern float lbl_805A29DC;

extern "C" void fn_801260DC(Context* self, clSegment2D* input, Vec2f* out) {
    u16 mask;
    bool checkAttached;
    grCollisionLine* attached;
    int offset;
    u16 count;
    u32 i;
    count = self->group->count;
    mask = fn_80121214(self);
    float upper = self->group->top - lbl_805A29DC;
    float lower;
    float left = lbl_805A29DC + self->group->left;
    float right = self->group->right - lbl_805A29DC;
    if (self->owner->kind == 1)
        lower = self->object->slot9().m_y;
    else
        lower = lbl_805A29DC + self->group->bottom;
    float x = self->x;
    float y = self->object->slot8().m_y;
    float downY = self->object->slot9().m_y;
    float topY = self->object->slot12().m_y;
    float unusedLeft = self->object->slot10().m_y;
    float unusedRight = self->object->slot11().m_y;
    Entry current;
    Entry next;
    attached = self->attached.line;
    GroundData* ground = self->attached.ground;
    grCollision* collision = self->attached.collision;
    checkAttached = self->owner->kind == 1;
    if (checkAttached) {
        bool valid = attached && ground && collision;
        if (valid && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            checkAttached = true;
        else
            checkAttached = false;
    }
    clSegment2D segment;
    clSegment2D edge;
    Vec2f point;
    i = 0;
    offset = 0;
    for (; i < count; offset += 16, ++i) {
        current = *(Entry*)((char*)self->group->entries + offset);
        if (!(*(u16*)((char*)current.line + 0xe) & mask)) continue;
        if (current.byte) continue;
        if ((*(u8*)((char*)current.line + 0xf) & 1) &&
            fn_80137114(self->owner, &current)) continue;
        current.collision->getSegment(&segment, current.line);
        u8 flags = *(u8*)((char*)current.line + 0xf);
        if ((flags >> 1) & 1) {
            if (segment.m_p1Pos.m_x <= x && x <= segment.m_p0Pos.m_x &&
                fn_800408C4(&segment, input, &point) &&
                y < point.m_y && point.m_y < upper)
                upper = point.m_y;
        } else if (flags & 1) {
            if (segment.m_p0Pos.m_x <= x && x <= segment.m_p1Pos.m_x &&
                fn_800408C4(&segment, input, &point) &&
                lower < point.m_y && point.m_y < y) {
                lower = point.m_y;
                self->selected = current;
            }
        } else if ((flags >> 2) & 1) {
            if (checkAttached) {
                if (fn_80113EC0(&current, &next) && next.enabled() && next.same(attached))
                    continue;
                if (fn_80113F88(&current, &next) && next.enabled() && next.same(attached))
                    continue;
            }
            if (segment.m_p1Pos.m_y <= y && y <= segment.m_p0Pos.m_y) {
                if (fn_8004094C(&segment, &input->m_p0Pos, &point) &&
                    left < point.m_x && point.m_x < x)
                    left = point.m_x;
            } else if (segment.m_p0Pos.m_x < x &&
                       downY <= segment.m_p0Pos.m_y && segment.m_p0Pos.m_y <= y) {
                edge.m_p0Pos.m_x = self->leftPos.m_x;
                edge.m_p0Pos.m_y = self->leftPos.m_y;
                edge.m_p1Pos.m_x = self->centerPos.m_x;
                edge.m_p1Pos.m_y = self->centerPos.m_y;
                if (fn_8004094C(&edge, &segment.m_p0Pos, &point)) {
                    float value = self->leftPos.m_x + (segment.m_p0Pos.m_x - point.m_x);
                    if (left < value && value < x) left = value;
                }
            } else if (segment.m_p1Pos.m_x < x &&
                       y <= segment.m_p1Pos.m_y && segment.m_p1Pos.m_y <= topY) {
                edge.m_p0Pos.m_x = self->leftPos.m_x;
                edge.m_p0Pos.m_y = self->leftPos.m_y;
                edge.m_p1Pos.m_x = self->topPos.m_x;
                edge.m_p1Pos.m_y = self->topPos.m_y;
                if (fn_8004094C(&edge, &segment.m_p1Pos, &point)) {
                    float value = self->leftPos.m_x + (segment.m_p1Pos.m_x - point.m_x);
                    if (left < value && value < x) left = value;
                }
            }
        } else if ((flags >> 3) & 1) {
            if (checkAttached) {
                if (fn_80113DF8(&current, &next) && next.enabled() && next.same(attached))
                    continue;
                if (fn_80114024(&current, &next) && next.enabled() && next.same(attached))
                    continue;
            }
            if (segment.m_p0Pos.m_y <= y && y <= segment.m_p1Pos.m_y) {
                if (fn_8004094C(&segment, &input->m_p0Pos, &point) &&
                    x < point.m_x && point.m_x < right)
                    right = point.m_x;
            } else if (x < segment.m_p1Pos.m_x &&
                       downY <= segment.m_p1Pos.m_y && segment.m_p1Pos.m_y <= y) {
                edge.m_p0Pos.m_x = self->rightPos.m_x;
                edge.m_p0Pos.m_y = self->rightPos.m_y;
                edge.m_p1Pos.m_x = self->centerPos.m_x;
                edge.m_p1Pos.m_y = self->centerPos.m_y;
                if (fn_8004094C(&edge, &segment.m_p1Pos, &point)) {
                    float value = self->rightPos.m_x + (segment.m_p1Pos.m_x - point.m_x);
                    if (x < value && value < right) right = value;
                }
            } else if (x < segment.m_p0Pos.m_x &&
                       y <= segment.m_p0Pos.m_y && segment.m_p0Pos.m_y <= topY) {
                edge.m_p0Pos.m_x = self->rightPos.m_x;
                edge.m_p0Pos.m_y = self->rightPos.m_y;
                edge.m_p1Pos.m_x = self->topPos.m_x;
                edge.m_p1Pos.m_y = self->topPos.m_y;
                if (fn_8004094C(&edge, &segment.m_p0Pos, &point)) {
                    float value = self->rightPos.m_x + (segment.m_p0Pos.m_x - point.m_x);
                    if (x < value && value < right) right = value;
                }
            }
        }
    }
    self->up.m_x = x;
    self->up.m_y = upper;
    self->down.m_x = x;
    self->down.m_y = lower;
    self->right.m_x = right;
    self->right.m_y = y;
    self->left.m_x = left;
    self->left.m_y = y;
    out->m_x = right - left;
    out->m_y = upper - lower;
}
