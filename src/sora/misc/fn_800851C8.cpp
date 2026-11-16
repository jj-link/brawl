#include <types.h>
#include <nw4r/math/math_types.h>
#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_prng.h>
#pragma force_active on

using namespace nw4r::math;

struct Node;
struct Link {
    Node* parent;
    Node* child;
    VEC3 axis0;
    f32 limit0;
    VEC3 axis1;
    VEC3 axis2;
    f32 limit1;
    f32 limit2;
};
struct Node {
    s32 kind;
    char pad04[0x24];
    VEC3 initial;
    VEC3 position;
    VEC3 anchor;
    VEC3 previous;
    VEC3 oldAnchor;
    char pad64[0x20];
    f32 length;
    char pad88[0x28];
    f32 weight;
    char padB4[0x0c];
    f32 blend;
    f32 gravityThreshold;
    char padC8[8];
    f32 time;
    f32 duration;
    char padD8[4];
    MTX34 matrix;
    char pad10C[0x60];
    MTX34 localMatrix;
    char pad19C[0x28];
    u8 matrixFlag;
    char pad1C5[0x13];
    VEC3 velocity;
    char pad1E4[8];
    f32 disturbance;
    char pad1F0[5];
    u8 movementFlag;
    u8 collisionFlag;
    char pad1F7;
    Link* parent;
    Link** children;
    s32 childCount;
};
struct Context {
    char pad00[0x48];
    f32 scale;
};
extern "C" {
void fn_801EC158(MTX34*);
void fn_801EC41C(const MTX34*, MTX34*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
void fn_801EC868(const MTX34*, MTX34*, f32, f32, f32);
void fn_801EC8DC(const MTX34*, MTX34*, f32, f32, f32);
void fn_8003E388(const MTX34*, MTX34*);
void fn_8003E5B4(MTX34*);
void fn_8003E6DC(const MTX34*, VEC3*);
void fn_8009BD44(const MTX34*, MTX34*, MTX34*);
f32 fn_8009BAFC(VEC3, VEC3);
void fn_8009BC34(MTX34*, VEC3, const f32&);
void fn_801ED008(const VEC3*, VEC3*);
f32 fn_801ED04C(const VEC3*);
void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
void fn_800893F0(Context*, Node*);
s32 fn_800867E8(Context*, Node*, u8, VEC2*);
s32 fn_800879FC(Context*, Node*, u8, s32);
void fn_80088FB8(Context*, Node*, s32);
void fn_80081FFC(Node*, const MTX34*, VEC3*, VEC3*);
void fn_80081DC4(Node*);
s32 fn_803F6150(const void*, const void*, u32);
extern const f32 lbl_805A1BB8;
extern const f32 lbl_805A1BBC;
extern const f32 lbl_805A1BD8;
extern const f32 lbl_805A1BEC;
extern const f32 lbl_805A1BF0;
extern const f32 lbl_805A1C10;
extern const f32 lbl_805A1C14;
extern const f32 lbl_805A1C18;
extern const f32 lbl_805A1C1C;
}
static inline bool different(const MTX34& a, const MTX34& b) {
    return fn_803F6150(&a, &b, 0x30) != 0;
}
static inline bool isSmall(f32 value) {
    bool result = false;
    if (f32(fabs(value)) < lbl_805A1BF0)
        result = true;
    return result;
}
static inline bool isNan(f32 value) {
    u32 bits = *(u32*)&value;
    bool result = false;
    if (((bits >> 23) & 255) == 255 && (bits & 0x7fffff) != 0)
        result = true;
    return result;
}
static inline bool matrixIsNan(const MTX34& matrix) {
    bool result = isNan(matrix._00);
    result = result || isNan(matrix._01);
    result = result || isNan(matrix._02);
    result = result || isNan(matrix._03);
    result = result || isNan(matrix._10);
    result = result || isNan(matrix._11);
    result = result || isNan(matrix._12);
    result = result || isNan(matrix._13);
    result = result || isNan(matrix._20);
    result = result || isNan(matrix._21);
    result = result || isNan(matrix._22);
    result = result || isNan(matrix._23);
    return result;
}
extern "C" s32 fn_800851C8(
    Context* self, Node* node, s32 arg2, f32* scale,
    s32 useParentPosition, s32 useInitial, s32 suppressMovement,
    s32 conditionalParent, u8 collisionMode, u8 timeMode,
    u8 randomize, u8 constrain)
{
    s32 offset;
    s32 result = 0;
    s32 hit = 0;
    s32 moved = 0;
    MTX34 identity;
    MTX34 parentMatrix, normalizedParent, scaled, normalizedScale;
    MTX34 inverse, positionMatrix, anchorMatrix, rotation, unusedTranslation;
    MTX34 localRotation, localScale, transformed;
    MTX34 correctionResult, correctionCopy, correctionSecond, correctionThird;
    MTX34 local, kindLocal, translated, rotationResult;
    VEC2 contact;
    fn_801EC158(&identity);
    f32 time = node->time;
    f32 duration = node->duration;
    if (lbl_805A1BB8 != node->weight &&
        (timeMode != 2 || time < duration * lbl_805A1C10) &&
        node->parent != 0)
    {
        parentMatrix = node->parent->parent->matrix;
        if (constrain) {

            VEC3 unit(lbl_805A1BBC, lbl_805A1BBC, lbl_805A1BBC);
            fn_8003E388(&parentMatrix, &normalizedParent);
            fn_8003E5B4(&normalizedParent);
            scaled = normalizedParent;
            fn_801EC8DC(&scaled, &scaled, unit.x, unit.y, unit.z);
            translated = scaled;
            translated._03 = parentMatrix._03;
            translated._13 = parentMatrix._13;
            translated._23 = parentMatrix._23;
            parentMatrix = translated;
        }
        if (node->kind == 0) {
            VEC3 target;
            if (useParentPosition)
                target = node->parent->parent->position;
            else if (lbl_805A1BB8 != node->parent->parent->weight)
                target = node->parent->parent->position;
            else if (useInitial)
                target = node->initial;
            else
                target = node->anchor;
            VEC3 delta = target - node->anchor;
            node->anchor += delta;
            if (randomize) {
                f32 old = node->disturbance;
                f32 adjustment;
                if (lbl_805A1BBC * randf() > lbl_805A1C14) {
                    if (old < lbl_805A1BB8)
                        adjustment = old - self->scale *
                            (lbl_805A1BD8 * (lbl_805A1BBC * randf()));
                    else
                        adjustment = old + self->scale *
                            (lbl_805A1BD8 * (lbl_805A1BBC * randf()));
                } else {
                    adjustment = lbl_805A1BB8;
                }
                node->disturbance = node->disturbance - adjustment;
                node->anchor.y += node->disturbance;
            }
            fn_800893F0(self, node);
            bool limited = f32(fabs(node->gravityThreshold)) >= lbl_805A1C18;
            if (!limited) {
                node->position += VEC3(lbl_805A1BB8, lbl_805A1BEC, lbl_805A1BB8) *
                    node->weight * *scale * self->scale;
            }
            VEC3 direction = node->position - node->anchor;
            if (lbl_805A1BB8 != fn_801ED04C(&direction))
                fn_801ED008(&direction, &direction);
            node->position = node->anchor + direction * node->length;
            if (node->collisionFlag)
                fn_80088FB8(self, node, arg2);
            if (constrain &&
                (node->childCount == 0 ||
                 (node->childCount != 0 && node->children[0]->child->kind != 0)))
                hit = fn_800867E8(self, node, collisionMode, &contact);
            moved = fn_800879FC(self, node, constrain, 0);
            if (!suppressMovement) {
                if (hit) moved = 1;
                if (!node->movementFlag) moved = 1;
            } else {
                moved = 0;
            }
            VEC3 oldStart;
            VEC3 oldEnd;
            fn_80081FFC(node, &node->localMatrix, &oldStart, &oldEnd);
            VEC3 matrixScale;
            fn_8003E388(&parentMatrix, &normalizedScale);
            fn_8003E6DC(&normalizedScale, &matrixScale);
            if (isSmall(matrixScale.x) ||
                isSmall(matrixScale.y) ||
                isSmall(matrixScale.z))
                parentMatrix = identity;
            fn_801EC41C(&parentMatrix, &inverse);
            fn_801EC868(&identity, &positionMatrix,
                        node->position.x, node->position.y, node->position.z);
            fn_801EC868(&identity, &anchorMatrix,
                        node->anchor.x, node->anchor.y, node->anchor.z);
            fn_801EC1B8(&inverse, &positionMatrix, &positionMatrix);
            fn_801EC1B8(&inverse, &anchorMatrix, &anchorMatrix);
            VEC3 localPosition;
            localPosition.x = positionMatrix._03;
            localPosition.y = positionMatrix._13;
            localPosition.z = positionMatrix._23;
            VEC3 localAnchor;
            localAnchor.x = anchorMatrix._03;
            localAnchor.y = anchorMatrix._13;
            localAnchor.z = anchorMatrix._23;
            VEC3 oldDirection = oldStart - oldEnd;
            VEC3 newDirection = localPosition - localAnchor;
            if (limited) {
                VEC3 difference;
                difference = newDirection - oldDirection;
                difference *= node->blend;
                newDirection = oldDirection + difference;
            }
            f32 angle = fn_8009BAFC(oldDirection, newDirection);
            VEC3 axis;
            fn_801ED0B0(&oldDirection, &newDirection, &axis);
            fn_8009BC34(&rotationResult, axis, angle);
            rotation = rotationResult;
            fn_801EC868(&identity, &unusedTranslation,
                        localAnchor.x, localAnchor.y, localAnchor.z);
            if (different(rotation, identity)) {
                fn_8009BD44(&node->localMatrix, &localRotation, &localScale);
                fn_801EC1B8(&rotation, &localScale, &transformed);
                VEC3 start;
                VEC3 end;
                fn_80081FFC(node, &transformed, &start, &end);
                VEC3 currentDirection = start - end;
                if (!constrain) {
                    f32 currentAngle = fn_8009BAFC(node->parent->axis0, currentDirection);
                    if (currentAngle > node->parent->limit0) {
                        VEC3* reference = &node->parent->axis0;
                        f32 correction = currentAngle - ((f32*)reference)[3];
                        VEC3 correctionAxis;
                        fn_801ED0B0(reference, &currentDirection, &correctionAxis);
                        fn_8009BC34(&correctionResult, correctionAxis, -correction);
                        correctionCopy = correctionResult;
                        fn_801EC1B8(&correctionCopy, &transformed, &transformed);
                        fn_80081FFC(node, &transformed, &start, &end);
                        currentDirection = start - end;
                    }
                }
                if (!constrain) {
                    f32 currentAngle = fn_8009BAFC(node->parent->axis1, currentDirection);
                    if (currentAngle < lbl_805A1C1C) {
                        f32 difference = lbl_805A1C1C - currentAngle;
                        if (difference > node->parent->limit1) {
                            f32 correction = difference - node->parent->limit1;
                            VEC3 correctionAxis;
                            fn_801ED0B0(&node->parent->axis1, &currentDirection, &correctionAxis);
                            fn_8009BC34(&correctionSecond, correctionAxis, correction);
                            fn_801EC1B8(&correctionSecond, &transformed, &transformed);
                        }
                    } else {
                        currentAngle = fn_8009BAFC(node->parent->axis2, currentDirection);
                        f32 limit = node->parent->limit2;
                        f32 difference = lbl_805A1C1C - currentAngle;
                        limit = f32(fabs(limit));
                        if (difference > limit) {
                            f32 correction = difference - limit;
                            VEC3 correctionAxis;
                            fn_801ED0B0(&node->parent->axis2, &currentDirection, &correctionAxis);
                            fn_8009BC34(&correctionThird, correctionAxis, correction);
                            fn_801EC1B8(&correctionThird, &transformed, &transformed);
                        }
                    }
                }
                fn_801EC1B8(&localRotation, &transformed, &transformed);
                local = transformed;
                if (node->matrixFlag) {
                    if (conditionalParent) {
                        if (lbl_805A1BB8 != node->parent->parent->weight)
                            node->matrix = parentMatrix;
                    } else {
                        node->matrix = parentMatrix;
                    }
                } else {
                    fn_801EC1B8(&parentMatrix, &local, &node->matrix);
                }
                fn_80081DC4(node);
            } else {
                if (matrixIsNan(node->localMatrix)) {}
                fn_801EC1B8(&parentMatrix, &node->localMatrix, &node->matrix);
                fn_80081DC4(node);
            }
        } else {
            kindLocal = node->localMatrix;
            fn_801EC1B8(&parentMatrix, &kindLocal, &node->matrix);
            fn_80081DC4(node);
        }
        VEC3 velocity;
        velocity = node->position - node->previous;
        node->velocity = velocity;
        node->previous = node->position;
        node->oldAnchor = node->anchor;
    } else {
        node->previous = node->position;
        node->oldAnchor = node->anchor;
    }
    s32 i = 0;
    offset = 0;
    for (; i < *(s32*)((char*)node + 0x200); offset += 4, ++i) {
        if (*(s32*)((char*)node->children + offset) != 0)
            result = fn_800851C8(self,
                                 (*(Link**)((char*)node->children + offset))->child, arg2, scale,
                                 useParentPosition, useInitial, 0,
                                 conditionalParent, collisionMode, timeMode,
                                 randomize, constrain);
    }
    if (result % 10 != 0 && result / 10 != 0)
        return result;
    if (result % 10 == 0) {
        if (hit) result += 2;
        else if (moved &&
                 (node->childCount == 0 ||
                  (node->childCount != 0 && node->children[0]->child->kind != 0)))
            result += 1;
    }
    if (result / 10 == 0 && moved) {
        if ((lbl_805A1BB8 != node->weight && node->parent != 0) || node->kind != 0) {
            if (node->parent == 0 || node->parent->parent->kind == 0)
                goto done;
        }
        result += 10;
    }
done:
    return result;
}
