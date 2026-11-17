#include <types.h>
#include <mt/mt_vector.h>
#include <mt/mt_coll2d.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct GroundData { u8 pad[0x54]; u8 flags; };
struct LineData {
    u8 pad[0xf];
    u8 high : 3;
    u8 target : 1;
    u8 right : 1;
    u8 left : 1;
    u8 upper : 1;
    u8 under : 1;
};
struct Entry {
    LineData* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;
    bool valid() const { return line && ground && collision; }
    int enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1)) return 1;
        return 0;
    }
    int pairEnabled() const {
        bool ok = false;
        bool pair = line && ground;
        if (pair && collision) ok = true;
        if (ok && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1)) return 1;
        return 0;
    }
};
struct List { u8 pad[0x1a]; u16 count; Entry* entries; };
struct Self { u8 pad[0x10]; List* list; };
struct Segment : clSegment2D { int extra; };
struct Hit { u8 failed; Vec2f p; u8 pValid; Vec2f q; u8 qValid; };

extern "C" {
void fn_8003DBA8(Vec2f*);
int fn_800409D4(Segment*, Segment*);
int fn_80041218(clCircle2D*, Segment*);
void fn_8008734C(Hit*, Self*, Segment*, Segment*);
void fn_800876BC(Hit*, Self*, Segment*, Segment*);
void fn_8008785C(Hit*, Self*, Segment*, Segment*);
void fn_80111968(void*, Segment*, void*, int);
void fn_80113BD0(Entry*, Vec2f*);
void fn_80113BF8(Entry*, Vec2f*);
void fn_80113DF8(Entry*, Entry*);
void fn_80113EC0(Entry*, Entry*);
Vec2f fn_80114CBC(Entry*, Vec2f*);
Vec2f fn_80114E9C(Entry*);
float rsqrtf__Ff(float);
extern const float lbl_805A1BB8;
extern const float lbl_805A1BD8;
extern const float lbl_805A1C20;
extern const float lbl_805A1C24;
extern const float lbl_805A1C5C;
}

static inline float norm(Vec2f& v) {
    float d = v.lengthSq();
    return (float)(double)nw4r::ut::Abs(d) <= lbl_805A1C20
        ? lbl_805A1BB8 : d * rsqrtf__Ff(d);
}
static inline void add(Vec2f& a, const Vec2f& b) {
    a.m_x = a.m_x + b.m_x;
    a.m_y = a.m_y + b.m_y;
}
static inline void setCircle(clCircle2D& out, float x, float y, float radius) {
    out.m_centerPos.m_x = x;
    out.m_centerPos.m_y = y;
    out.m_radius = radius;
}
static inline void setVec(Vec2f& out, float x, float y) {
    out.m_x = x;
    out.m_y = y;
}
#define F(p,o) (*(float*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define SOLVE(h,s) \
    if ((float)(double)nw4r::ut::Abs((s).m_p0Pos.m_x - (s).m_p1Pos.m_x) < lbl_805A1C24) \
        fn_800876BC(&(h), self, &(s), &movement); \
    else if ((float)(double)nw4r::ut::Abs((s).m_p0Pos.m_y - (s).m_p1Pos.m_y) < lbl_805A1C24) \
        fn_8008785C(&(h), self, &(s), &movement); \
    else fn_8008734C(&(h), self, &(s), &movement);

extern "C" int fn_800879FC(Self* self, char* arg, int unused, int ignore) {
    Segment movement;
    Segment segment;
    Hit initial;
    Segment segmentA;
    Segment segmentB;
    Hit hitA;
    Hit hitB;
    Hit hitC;
    Hit hitD;
    Entry neighborA;
    Entry neighborB;
    clCircle2D circleA;
    clCircle2D circleB;
    Vec2f end;
    Vec2f start;
    Vec2f forward;
    Vec2f backward;
    Vec2f result;
    Vec2f pointA;
    Vec2f pointB;
    Vec2f normal;
    Vec2f endpointA;
    Vec2f endpointB;
    Vec2f edgeNormal;
    Vec2f edgeA;
    Vec2f edgeB;
    Vec2f neighborPointA;
    Vec2f towardA;
    Vec2f normalA;
    Vec2f neighborPointB;
    Vec2f towardB;
    Vec2f normalB;
    Vec2f alongA;
    Vec2f alongB;
    Vec2f extendedA;
    Vec2f extendedB;
    Vec2f distAA;
    Vec2f distAB;
    Vec2f otherNormalA;
    Vec2f deltaA;
    Vec2f otherNormalB;
    Vec2f deltaB;
    Vec2f distBA;
    Vec2f distBB;
    Vec2f otherNormalC;
    Vec2f deltaC;
    Vec2f otherNormalD;
    Vec2f deltaD;
    Vec2f previous;
    Vec2f finalA;
    Vec2f finalB;
    end = *(Vec2f*)(arg+0x34);
    start = *(Vec2f*)(arg+0x40);
    Entry* e;
    int offset;
    int found = 0;
    Vec2f::copy(forward, end - start);
    Vec2f::copy(backward, start - end);
    fn_8003DBA8(&forward);
    fn_8003DBA8(&backward);
    add(start, backward * lbl_805A1BD8);
    add(end, forward * lbl_805A1BD8);
    movement.m_p0Pos = end;
    movement.m_p1Pos = start;
    movement.extra = 0;
    pointA.m_x = lbl_805A1BB8;
    pointA.m_y = lbl_805A1BB8;
    pointB.m_x = lbl_805A1BB8;
    pointB.m_y = lbl_805A1BB8;
    int blockedA = 0;
    int blockedB = 0;
    unsigned int i = 0;
    offset = 0;
    while (i < self->list->count) {
        e = (Entry*)((char*)self->list->entries + offset);
        if (!e->line->target) goto next;
        if (!((e->ground->flags >> 6) & 1)) goto next;
        fn_80111968(e->collision, &segment, e->line, 0);
        if (e->line->left || e->line->right) {
            if (B(arg,0x1f4) == 0) { found = 0; goto next; }
        }
        if (ignore) {
            if (e->line->under) goto next;
            if (e->line->upper) goto next;
        }
        Vec2f::copy(normal, fn_80114E9C(e));
        fn_8003DBA8(&normal);
        if (forward.m_x * normal.m_x + forward.m_y * normal.m_y > lbl_805A1BB8) goto next;
        if (!fn_800409D4(&segment, &movement)) goto next;
        found = 1;
        result = end;
        SOLVE(initial,segment)
        if (!initial.failed) { pointA = initial.p; pointB = initial.q; }
        endpointA.m_x = lbl_805A1BB8;
        endpointA.m_y = lbl_805A1BB8;
        endpointB.m_x = lbl_805A1BB8;
        endpointB.m_y = lbl_805A1BB8;
        neighborA.line = 0; neighborA.ground = 0; neighborA.collision = 0; neighborA.byte = 0; neighborA.flag = 0;
        neighborB.line = 0; neighborB.ground = 0; neighborB.collision = 0; neighborB.byte = 0; neighborB.flag = 0;
        fn_80113EC0(e,&neighborA);
        fn_80113DF8(e,&neighborB);
        if (e->enabled()) {
            Vec2f::copy(edgeNormal,fn_80114E9C(e));
            fn_8003DBA8(&edgeNormal);
            fn_80113BD0(e,&edgeA);
            fn_80113BF8(e,&edgeB);
            if (neighborA.pairEnabled()) {
                fn_80111968(neighborA.collision,&segmentA,neighborA.line,0);
                fn_80113BD0(&neighborA,&neighborPointA);
                endpointA = fn_80114CBC(e,&neighborPointA);
                Vec2f::copy(towardA,start-endpointA);
                fn_8003DBA8(&towardA);
                Vec2f::copy(normalA,fn_80114E9C(&neighborA));
                fn_8003DBA8(&normalA);
                float dotA = normalA.m_x*towardA.m_x + normalA.m_y*towardA.m_y;
                float dotB = edgeNormal.m_x*towardA.m_x + edgeNormal.m_y*towardA.m_y;
                blockedA = 0;
                if (dotA > lbl_805A1BB8 && dotB > lbl_805A1BB8) blockedA = 1;
            } else { endpointA = edgeA; endpointB = edgeB; }
            if (neighborB.pairEnabled()) {
                fn_80111968(neighborB.collision,&segmentB,neighborB.line,0);
                fn_80113BD0(&neighborB,&neighborPointB);
                endpointB = fn_80114CBC(e,&neighborPointB);
                Vec2f::copy(towardB,start-endpointB);
                fn_8003DBA8(&towardB);
                Vec2f::copy(normalB,fn_80114E9C(&neighborB));
                fn_8003DBA8(&normalB);
                float dotA = normalB.m_x*towardB.m_x + normalB.m_y*towardB.m_y;
                float dotB = edgeNormal.m_x*towardB.m_x + edgeNormal.m_y*towardB.m_y;
                blockedB = 0;
                if (dotA > lbl_805A1BB8 && dotB > lbl_805A1BB8) blockedB = 1;
            } else { endpointA = edgeA; endpointB = edgeB; }
        }
        Vec2f::copy(alongA,endpointA-start);
        Vec2f::copy(alongB,endpointB-start);
        fn_8003DBA8(&alongA);
        fn_8003DBA8(&alongB);
        Vec2f::copy(extendedA,start+alongA*F(arg,0x84));
        Vec2f::copy(extendedB,start+alongB*F(arg,0x84));
        setCircle(circleA,pointA.m_x,pointA.m_y,lbl_805A1C5C);
        setCircle(circleB,pointB.m_x,pointB.m_y,lbl_805A1C5C);
        if (!fn_80041218(&circleA,&segment)) {
            Vec2f::copy(distAA,endpointA-pointA);
            Vec2f::copy(distAB,endpointB-pointA);
            float lengthA = norm(distAA);
            float lengthB = norm(distAB);
            if (lengthA < lengthB) {
                if (!blockedA) { pointA = extendedA; goto second; }
                if (!neighborA.enabled()) goto second;
                Vec2f::copy(otherNormalA,fn_80114E9C(&neighborA));
                Vec2f::copy(deltaA,pointA-endpointA);
                if (otherNormalA.m_x*deltaA.m_x+otherNormalA.m_y*deltaA.m_y < lbl_805A1BB8) {
                    if (!blockedB) pointA = extendedB;
                    goto second;
                }
                if (!fn_800409D4(&segmentA,&movement)) goto second;
                SOLVE(hitA,segmentA)
                if (!hitA.failed) {
                    if (hitA.pValid && hitA.qValid) { pointA = hitA.q; goto second; }
                    if (hitA.pValid) { pointA = hitA.p; goto second; }
                    if (hitA.qValid) { pointA = hitA.q; goto second; }
                    pointA = extendedA;
                } else pointA = extendedA;
                goto second;
            } else {
                if (!blockedB) { pointA = extendedB; goto second; }
                if (!neighborB.enabled()) goto second;
                Vec2f::copy(otherNormalB,fn_80114E9C(&neighborB));
                Vec2f::copy(deltaB,pointA-endpointB);
                if (otherNormalB.m_x*deltaB.m_x+otherNormalB.m_y*deltaB.m_y < lbl_805A1BB8) {
                    if (!blockedA) pointA = extendedA;
                    goto second;
                }
                if (!fn_800409D4(&segmentB,&movement)) goto second;
                SOLVE(hitB,segmentB)
                if (!hitB.failed) {
                    if (hitB.pValid && hitB.qValid) { pointA = hitB.p; goto second; }
                    if (hitB.pValid) { pointA = hitB.p; goto second; }
                    if (hitB.qValid) { pointA = hitB.q; goto second; }
                    pointA = extendedB;
                } else pointA = extendedB;
            }
        }
second:
        if (!fn_80041218(&circleB,&segment)) {
            Vec2f::copy(distBA,endpointA-pointB);
            Vec2f::copy(distBB,endpointB-pointB);
            float lengthA = norm(distBA);
            float lengthB = norm(distBB);
            if (lengthA < lengthB) {
                if (!blockedA) { pointB = extendedA; goto adjust; }
                if (!neighborA.enabled()) goto adjust;
                Vec2f::copy(otherNormalC,fn_80114E9C(&neighborA));
                Vec2f::copy(deltaC,pointB-endpointA);
                if (otherNormalC.m_x*deltaC.m_x+otherNormalC.m_y*deltaC.m_y < lbl_805A1BB8) {
                    if (!blockedB) pointB = extendedB;
                    goto adjust;
                }
                if (!fn_800409D4(&segmentA,&movement)) goto adjust;
                SOLVE(hitC,segmentA)
                if (!hitC.failed) {
                    if (hitC.pValid && hitC.qValid) { pointB = hitC.q; goto adjust; }
                    if (hitC.pValid) { pointB = hitC.p; goto adjust; }
                    if (hitC.qValid) { pointB = hitC.q; goto adjust; }
                    pointB = extendedA;
                } else pointB = extendedA;
                goto adjust;
            } else {
                if (!blockedB) { pointB = extendedB; goto adjust; }
                if (!neighborB.enabled()) goto adjust;
                Vec2f::copy(otherNormalD,fn_80114E9C(&neighborB));
                Vec2f::copy(deltaD,pointB-endpointB);
                if (otherNormalD.m_x*deltaD.m_x+otherNormalD.m_y*deltaD.m_y < lbl_805A1BB8) {
                    if (!blockedA) pointB = extendedA;
                    goto adjust;
                }
                if (!fn_800409D4(&segmentB,&movement)) goto adjust;
                SOLVE(hitD,segmentB)
                if (!hitD.failed) {
                    if (hitD.pValid && hitD.qValid) { pointB = hitD.p; goto adjust; }
                    if (hitD.pValid) { pointB = hitD.p; goto adjust; }
                    if (hitD.qValid) { pointB = hitD.q; goto adjust; }
                    pointB = extendedB;
                } else pointB = extendedB;
            }
        }
adjust:
        add(pointA, normal*lbl_805A1BD8);
        add(pointB, normal*lbl_805A1BD8);
next:
        offset += 0x10;
        ++i;
    }
    if (found) {
        setVec(previous,F(arg,0x4c),F(arg,0x50));
        Vec2f::copy(finalA,pointA-previous);
        Vec2f::copy(finalB,pointB-previous);
        float a = norm(finalA);
        float b = norm(finalB);
        result.m_x = (a < b ? pointA : pointB).m_x;
        result.m_y = (a < b ? pointA : pointB).m_y;
        F(arg,0x34) = result.m_x;
        F(arg,0x38) = result.m_y;
    }
    return found;
}
