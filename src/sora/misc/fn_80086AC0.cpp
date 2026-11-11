#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

extern "C" {
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;
extern const float lbl_805A1BE4;
extern const float lbl_805A1C20;

float mtSqrtf__Ff(float);
float rsqrtf__Ff(float);
void fn_8003DBA8(Vec2f*);
int fn_800409D4(void*, void*);
void fn_80111968(void*, void*, void*, int);
}

struct CollisionEntry {
    void* object;
    char padding[4];
    void* owner;
    char padding2[4];
};

struct CollisionList {
    char padding[0x1A];
    unsigned short count;
    CollisionEntry* entries;
};

struct CollisionOwner {
    char padding[0x10];
    CollisionList* list;
};

struct Segment2 {
    Vec2f a;
    Vec2f b;
    int flags;
};

static inline bool finiteComponent(float value) {
    bool result = true;
    if ((unsigned char)(*(unsigned int*)&value >> 23) == 0xFF)
        result = false;
    return result;
}

static inline bool finiteVector(const Vec2f& value) {
    return finiteComponent(value.m_x) && finiteComponent(value.m_y);
}

extern "C" int fn_80086AC0(CollisionOwner* self, unsigned char* arg1, int arg2) {
    Vec2f start(
        *(float*)(arg1 + 0x40),
        lbl_805A1BBC + *(float*)(arg1 + 0x44));
    Vec2f end(
        *(float*)(arg1 + 0x34),
        *(float*)(arg1 + 0x38));
    Vec2f previous(
        *(float*)(arg1 + 0x58),
        lbl_805A1BBC + *(float*)(arg1 + 0x5C));

    int result = 0;
    if (!finiteVector(start))
        return 0;
    if (!finiteVector(end))
        return 0;

    Vec2f movement;
    Vec2f::copy(movement, end - start);
    float radius = mtSqrtf__Ff(
        movement.m_x * movement.m_x + movement.m_y * movement.m_y);

    Segment2 movementSegment;
    movementSegment.a = start;
    movementSegment.b = end;
    movementSegment.flags = 0;

    CollisionEntry* entry;
    int offset;
    unsigned int i;
    i = 0;
    offset = 0;
    while (i < self->list->count) {
        entry = (CollisionEntry*)((char*)self->list->entries + offset);
        Segment2 collision;
        fn_80111968(entry->owner, &collision, entry->object, 0);

        if (fn_800409D4(&collision, &movementSegment)) {
            if (arg2 == 0) {
                unsigned char flags = *((unsigned char*)entry->object + 0xF);
                if (((flags >> 2) & 1) || ((flags >> 3) & 1)) {
                    result = 0;
                    goto next;
                }
            }

            Vec2f left;
            Vec2f right;
            Vec2f::copy(left, collision.a);
            Vec2f::copy(right, collision.b);
            if (collision.a.m_x > collision.b.m_x) {
                left = collision.b;
                right = collision.a;
            }

            Vec2f direction;
            Vec2f relative;
            Vec2f::copy(direction, right - left);
            Vec2f::copy(relative, start - left);
            float absolute;
            float dot = direction.m_x * relative.m_x +
                        direction.m_y * relative.m_y;
            float lengthSquared = direction.m_x * direction.m_x + direction.m_y * direction.m_y;
            absolute = (float)(double)nw4r::ut::Abs(lengthSquared);
            float length = absolute <= lbl_805A1C20
                ? lbl_805A1BB8
                : lengthSquared * rsqrtf__Ff(lengthSquared);

            fn_8003DBA8(&direction);
            float projection = dot / length;
            Vec2f projected;
            Vec2f perpendicular;
            Vec2f::copy(projected, left + direction * projection);
            Vec2f::copy(perpendicular, start - projected);
            float perpendicularSquared = perpendicular.lengthSq();
            float perpendicularLength =
                (float)(double)nw4r::ut::Abs(perpendicularSquared) <= lbl_805A1C20
                ? lbl_805A1BB8
                : perpendicularSquared * rsqrtf__Ff(perpendicularSquared);

            radius = mtSqrtf__Ff((float)(double)nw4r::ut::Abs(
                radius * radius - perpendicularLength * perpendicularLength));
            fn_8003DBA8(&relative);
            fn_8003DBA8(&movement);

            float distance;
            if (end.m_x - previous.m_x > lbl_805A1BB8)
                distance = projection + radius;
            else
                distance = projection - radius;

            Vec2f intersection;
            Vec2f::copy(intersection, left + direction * distance);
            float lower;
            float upper;
            if (left.m_x < right.m_x) {
                lower = left.m_x;
                upper = right.m_x;
            } else {
                lower = right.m_x;
                upper = left.m_x;
            }

            if (intersection.m_x > lower && intersection.m_x < upper) {
                *(float*)(arg1 + 0x34) = intersection.m_x;
                *(float*)(arg1 + 0x38) = intersection.m_y;
            } else {
                Vec2f fromLeft;
                Vec2f::copy(fromLeft, intersection - left);
                float leftSquared = fromLeft.lengthSq();
                float leftDistance =
                    (float)(double)nw4r::ut::Abs(leftSquared) <= lbl_805A1C20
                    ? lbl_805A1BB8
                    : leftSquared * rsqrtf__Ff(leftSquared);

                Vec2f fromRight;
                Vec2f::copy(fromRight, intersection - right);
                float rightSquared = fromRight.lengthSq();
                float rightDistance =
                    (float)(double)nw4r::ut::Abs(rightSquared) <= lbl_805A1C20
                    ? lbl_805A1BB8
                    : rightSquared * rsqrtf__Ff(rightSquared);

                Vec2f adjustment;
                Vec2f origin(
                    *(float*)(arg1 + 0x40),
                    *(float*)(arg1 + 0x44));
                if (leftDistance < rightDistance) {
                    Vec2f along;
                    Vec2f::copy(along, right - left);
                    fn_8003DBA8(&along);
                    Vec2f point;
                    Vec2f::copy(point, left + along * lbl_805A1BE4);
                    adjustment = point - origin;
                } else {
                    Vec2f along;
                    Vec2f::copy(along, left - right);
                    fn_8003DBA8(&along);
                    Vec2f point;
                    Vec2f::copy(point, right + along * lbl_805A1BE4);
                    adjustment = point - origin;
                }

                fn_8003DBA8(&adjustment);
                Vec2f answer;
                Vec2f::copy(answer, origin + adjustment * *(float*)(arg1 + 0x80));
                *(float*)(arg1 + 0x34) = answer.m_x;
                *(float*)(arg1 + 0x38) = answer.m_y;
            }

            result = 1;
            break;
        }

    next:
        offset += 0x10;
        ++i;
    }

    return result;
}
