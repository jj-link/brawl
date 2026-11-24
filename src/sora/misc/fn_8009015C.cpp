#include <mt/mt_common.h>
#include <nw4r/math/math_types.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

using namespace nw4r::math;

static inline VEC3 scaled(const VEC3& vector, f32 scale) {
    VEC3 result;
    LocalScale(static_cast<const Vec*>(vector), static_cast<Vec*>(result), scale);
    return result;
}

static inline void scaleInPlace(VEC3& vector, f32 scale) {
    LocalScale(static_cast<const Vec*>(vector), static_cast<Vec*>(vector), scale);
}

struct Node {
    char pad00[0x1c];
    VEC3 previousPosition;
    VEC3 previousAnchor;
    VEC3 position;
    VEC3 anchor;
    VEC3 oldPosition;
    char pad58[0x28];
    f32 length;
    char pad84[0x2c];
    f32 weight;
    char padB4[0x28];
    MTX34 matrix;
    char pad10C[0x60];
    MTX34 localMatrix;
    char pad19C[0x28];
    u8 flag1C4;
    char pad1C5[0x27];
    f32 value1EC;
    s32 kind;
};

struct State {
    Node** nodes;
    s32 count;
    char pad08[8];
    u8 flag10;
    char pad11[3];
    f32 pad14;
    f32 scale;
    s32 mode;
    char pad20[0x10];
    s32 last;
    char pad34[0x0e];
    u8 limit;
    u8 active;
    VEC3 direction;
    f32 distance;
    char pad54[3];
    u8 flag57;
    char pad58[2];
    u8 flag5A;
    char pad5B;
    u8 flag5C;
    char pad5D[8];
    u8 flag65;
};

static inline Node* followingNode(Node** nodes, s32 index) {
    u8* bytes = reinterpret_cast<u8*>(nodes);
    s32 offset = (index + 1) * sizeof(Node*);
    return *reinterpret_cast<Node**>(bytes + offset);
}

struct GlobalState {
    char pad00[0x58];
    void* object;

    void* getObject() const {
        if (object != 0)
            return object;
        return 0;
    }
};

extern "C" {
extern GlobalState* lbl_8049DEC8[];
extern const f32 lbl_805A1CA8;
extern const f32 lbl_805A1CAC;
extern const f32 lbl_805A1CD0;
extern const f32 lbl_805A1CD4;
extern const f32 lbl_805A1CD8;
extern const f32 lbl_805A1CDC;

void fn_8003DE70(VEC3*);
f32 fn_80086470(void*, f32, f32, f32);
f32 fn_8009BAFC(VEC3, VEC3);
MTX34 fn_8009BC34(VEC3, const f32*);
void fn_8009BD44(const MTX34*, MTX34*, MTX34*);
void fn_80162894(void*);
void fn_801629AC(MTX34*, f32, f32, f32);
void fn_801EC158(MTX34*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
void fn_801EC41C(const MTX34*, MTX34*);
void fn_801EC868(const MTX34*, MTX34*, f32, f32, f32);
void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
}

extern "C" void fn_8009015C(State* self) {
    MTX34 unused;
    MTX34 identity;
    MTX34 result;
    fn_80162894(&unused);
    fn_801EC158(&identity);

    if (self->flag57 >= 1)
        return;

    if (self->last < self->limit)
        self->limit = self->last;

    s32 limit = self->limit;
    s32 next = limit + 1;
    if (self->active >= next)
        return;
    if (self->last >= next)
        limit = next;

    void* object = lbl_8049DEC8[0]->getObject();

    for (s32 i = 1; i < self->count; ++i) {
        self->nodes[i]->previousPosition = self->nodes[i]->position;
        self->nodes[i]->previousAnchor = self->nodes[i]->anchor;
    }

    VEC3 delta;
    VEC3 unit;
    VEC3 direction = self->direction;
    MTX34 original = self->nodes[0]->matrix;
    MTX34 rotation, scaling, adjustment;
    fn_8009BD44(&original, &rotation, &scaling);

    VEC3 axis(lbl_805A1CAC, lbl_805A1CA8, lbl_805A1CA8);
    VEC3 directionCopy = direction;
    f32 angle = fn_8009BAFC(axis, directionCopy);
    if (static_cast<f32>(static_cast<f64>(FAbs(angle))) < lbl_805A1CD0) {
        VEC3 cross;
        fn_801ED0B0(&axis, &directionCopy, &cross);
        adjustment = fn_8009BC34(cross, &angle);
    } else {
        fn_801629AC(&adjustment, lbl_805A1CA8, lbl_805A1CA8,
                    lbl_805A1CD4 * angle);
    }
    fn_801EC1B8(&rotation, &adjustment, &result);
    self->nodes[0]->matrix = result;

    if (self->flag5C) {
        if (self->distance >= lbl_805A1CD8 &&
            (!self->flag10 || !self->mode)) {
            delta = self->direction;
            fn_8003DE70(&delta);
            LocalScale(static_cast<const Vec*>(delta), static_cast<Vec*>(delta),
                       -self->distance);
            for (s32 i = 0; i < self->active; ++i) {
                Node* node = self->nodes[self->last - i];
                node->position += delta;
                node->anchor += delta;
            }
            self->distance = lbl_805A1CA8;
            for (s32 i = 1; i < self->count; ++i) {
                delta = self->nodes[i]->anchor -
                        self->nodes[i]->previousAnchor;
                MTX34 translated;
                MTX34 current = self->nodes[i]->matrix;
                fn_801EC868(&current, &translated, delta.x, delta.y, delta.z);
                self->nodes[i]->matrix = translated;
            }
        }

        MTX34 parentMatrix;
        delta = self->nodes[0]->position - self->nodes[0]->oldPosition;
        for (s32 i = 1; i < self->count; ++i) {
            MTX34 translated;
            MTX34 current = self->nodes[i]->matrix;
            fn_801EC868(&current, &translated, delta.x, delta.y, delta.z);
            self->nodes[i]->matrix = translated;
            self->nodes[i]->position += delta;
            self->nodes[i]->anchor += delta;
        }

        for (s32 i = 1; i < self->count; ++i) {
            Node* node = self->nodes[i];
            if (node->flag1C4 && i != self->count - 1) {
                parentMatrix = self->nodes[i - 1]->matrix;
                VEC3 position(static_cast<const _VEC3&>(self->nodes[i - 1]->position));
                VEC3 anchor(static_cast<const _VEC3&>(self->nodes[i - 1]->anchor));
                self->nodes[i]->matrix = parentMatrix;
                self->nodes[i]->position = position;
                self->nodes[i]->anchor = anchor;
            } else if (lbl_805A1CA8 != node->weight) {
                delta = self->direction;
                fn_8003DE70(&delta);
                LocalScale(static_cast<const Vec*>(delta), static_cast<Vec*>(delta),
                           self->nodes[i - 1]->length);
                parentMatrix = self->nodes[i - 1]->matrix;
                fn_801EC868(&parentMatrix, &result, delta.x, delta.y, delta.z);
                self->nodes[i]->matrix = result;
                self->nodes[i]->anchor = self->nodes[i - 1]->position;
                delta = self->direction;
                fn_8003DE70(&delta);
                LocalScale(static_cast<const Vec*>(delta), static_cast<Vec*>(delta),
                           self->nodes[i]->length);
                self->nodes[i]->position = self->nodes[i]->anchor + delta;
            }
        }
        return;
    }

    delta = self->nodes[0]->position - self->nodes[0]->oldPosition;
    for (s32 i = 1; i < reinterpret_cast<s32*>(self)[1]; ++i) {
        MTX34 translated;
        MTX34 current = self->nodes[i]->matrix;
        fn_801EC868(&current, &translated, delta.x, delta.y, delta.z);
        self->nodes[i]->matrix = translated;
        self->nodes[i]->position += delta;
        self->nodes[i]->anchor += delta;
        self->nodes[i]->previousPosition += delta;
        self->nodes[i]->previousAnchor += delta;
    }

    for (s32 i = 0; i < self->active; ++i) {
        Node* node = self->nodes[self->last - i];
        node->position += scaled(self->direction, self->scale);
        node->anchor += scaled(self->direction, self->scale);
    }

    s32 wasStarted = 0;
    if (self->active == 0 && lbl_805A1CA8 == self->distance) {
        wasStarted = 1;
        if (self->count != 9 || self->nodes[8]->kind != 0x6b) {
            delta = self->nodes[self->last]->anchor - self->nodes[0]->anchor;
            f32 sq = delta.z * delta.z +
                     (delta.x * delta.x + delta.y * delta.y);
            f32 distance;
            if (static_cast<f32>(static_cast<f64>(FAbs(sq))) <= lbl_805A1CDC)
                distance = lbl_805A1CA8;
            else
                distance = sq * rsqrtf(sq);
            self->distance = distance;
        }
    }

    delta = self->direction;
    fn_8003DE70(&delta);
    f32 sq = self->direction.z * self->direction.z +
             (self->direction.x * self->direction.x +
              self->direction.y * self->direction.y);
    f32 length;
    if (static_cast<f32>(static_cast<f64>(FAbs(sq))) <= lbl_805A1CDC)
        length = lbl_805A1CA8;
    else
        length = sq * rsqrtf(sq);
    f32 step = length * self->scale;
    self->distance += step;
    LocalScale(static_cast<const Vec*>(delta), static_cast<Vec*>(delta),
               self->distance);

    for (;;) {
        while (self->active >= limit) {
        }

        if (self->distance < self->nodes[self->last - self->active]->length) {
            unit = self->direction;
            fn_8003DE70(&unit);
            VEC3 movement = scaled(unit, step);
            s32 index = self->last - self->active;
            Node* node = self->nodes[self->last - self->active];
            scaleInPlace(unit, node->length);
            if (self->active == 0) {
                if (wasStarted)
                    node->position += delta;
                else
                    node->position += movement;
                self->nodes[self->last - self->active]->anchor =
                    self->nodes[self->last - self->active]->position - unit;
            } else {
                ++index;
                Node* neighbor = self->nodes[index];
                self->nodes[self->last - self->active]->position = neighbor->anchor;
                self->nodes[self->last - self->active]->anchor =
                    self->nodes[self->last - self->active]->position - unit;
            }
            break;
        } else {
            unit = self->direction;
            fn_8003DE70(&unit);
            VEC3 movement = scaled(unit, step);
            s32 index = self->last - self->active;
            Node* node = self->nodes[index];
            scaleInPlace(unit, node->length);
            if (self->active == 0) {
                self->nodes[self->last - self->active]->position += movement;
                self->nodes[self->last - self->active]->anchor =
                    self->nodes[self->last - self->active]->position - unit;
            } else {
                Node* neighbor = followingNode(self->nodes, index);
                node->position = neighbor->anchor;
                self->nodes[self->last - self->active]->anchor =
                    self->nodes[self->last - self->active]->position - unit;
            }
            self->distance -= self->nodes[self->last - self->active]->length;

            delta = self->direction;
            fn_8003DE70(&delta);
            LocalScale(static_cast<const Vec*>(delta), static_cast<Vec*>(delta),
                       self->distance);

            if (++self->active < limit)
                continue;

            index = self->last - self->active;
            s32 neighborIndex = index;
            ++neighborIndex;
            Node* neighbor = self->nodes[neighborIndex];
            delta = self->nodes[index]->position - neighbor->anchor;
            for (s32 i = 0; i < self->active; ++i) {
                Node* moved = self->nodes[self->last - i];
                moved->position += delta;
                moved->anchor += delta;
            }
            self->distance = lbl_805A1CA8;
            break;
        }
    }

    for (s32 i = 1; i < self->count; ++i) {
        if (self->flag65 && i > self->last - self->active) {
            Node** nodes = self->nodes;
            f32 change = fn_80086470(
                object, nodes[i]->value1EC, lbl_805A1CAC, lbl_805A1CAC);
            nodes[i]->value1EC -= change;
            self->nodes[i]->position.y += self->nodes[i]->value1EC;
            delta = self->nodes[i]->position - self->nodes[i]->anchor;
            fn_8003DE70(&delta);
            LocalScale(static_cast<const Vec*>(delta), static_cast<Vec*>(delta),
                       self->nodes[i]->length);
            self->nodes[i]->position = self->nodes[i]->anchor + delta;
            if (i != self->count - 1)
                self->nodes[i + 1]->anchor = self->nodes[i]->position;
        }

        delta = self->nodes[i]->anchor - self->nodes[0]->anchor;
        MTX34 translated;
        MTX34 current = self->nodes[0]->matrix;
        fn_801EC868(&current, &translated, delta.x, delta.y, delta.z);
        self->nodes[i]->matrix = translated;
    }

    if (self->active >= limit) {
        self->flag5A = 3;
        self->active = self->limit + 1;
    }

    for (s32 i = 0; i < self->count; ++i) {
        MTX34 local;
        if (i == 0) {
            local = identity;
        } else {
            MTX34 current;
            MTX34 parent = self->nodes[i - 1]->matrix;
            MTX34 inverse;
            fn_801EC41C(&parent, &inverse);
            current = self->nodes[i]->matrix;
            fn_801EC1B8(&inverse, &current, &local);
        }
        self->nodes[i]->localMatrix = local;
    }
}
