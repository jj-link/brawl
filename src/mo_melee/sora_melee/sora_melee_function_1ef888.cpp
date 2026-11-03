#include <gf/gf_heap_manager.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

#pragma fp_contract off

struct Target {
    char padding00[0x3e];
    unsigned char playerMask;
    char padding3f;
    unsigned int flags;
};

struct TargetManager {
    char padding00[0x350];
    unsigned short count;
};

struct Point2 {
    float x;
    float y;
};

extern "C" {
extern const float lbl_27_rodata_2B80[];

void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void free__13gfHeapManagerFPv(void*);
float rsqrtf__Ff(float);

Target* fn_27_1EF3AC(TargetManager*, Target*, int);
void fn_27_1EF144(TargetManager*, Target**, Point2*, float*, Target*);
Target* fn_27_1EFC8C(TargetManager*, Target*, Target*, Target**, int,
                     float, float, float);
}

extern "C" Target* fn_27_1EF888(
    TargetManager* manager, Target* current, const Point2* position,
    Target* excluded, int player, float arg0, float arg1, float distanceScale)
{
    const float* const constants = lbl_27_rodata_2B80;
    int playerBit;
    Target** targets;
    float* scores;
    Point2* positions;
    targets = static_cast<Target**>(
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(12, manager->count * 4));
    scores = static_cast<float*>(
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(12, manager->count * 4));
    positions = static_cast<Point2*>(
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(12, manager->count * 8));

    if (!targets || !scores || !positions) {
        if (targets)
            free__13gfHeapManagerFPv(targets);
        if (scores)
            free__13gfHeapManagerFPv(scores);
        if (positions)
            free__13gfHeapManagerFPv(positions);
        return current;
    }

    if (!excluded)
        excluded = fn_27_1EF3AC(manager, current, player);

    fn_27_1EF144(manager, targets, positions, scores, excluded);

    playerBit = 1 << player;
    Target** targetIt = targets;
    float* scoreIt = scores;
    Point2* positionIt = positions;
    for (int i = 0; i < manager->count;
         ++i, ++targetIt, ++scoreIt, ++positionIt) {
        if (*targetIt) {
            if (*targetIt == excluded) {
                *targetIt = 0;
            } else {
                float x = position->x;
                float y = position->y;
                Vec2f origin(x, y);
                Vec2f difference;
                difference.m_x = origin.m_x - positionIt->x;
                difference.m_y = origin.m_y - positionIt->y;
                float square = difference.m_x * difference.m_x +
                               difference.m_y * difference.m_y;
                float distance;
                if (static_cast<float>(
                        static_cast<double>(nw4r::ut::Abs(square))) <= constants[28])
                    distance = constants[2];
                else
                    distance = square * rsqrtf__Ff(square);

                *scoreIt += distanceScale * distance;

                unsigned int flags = (*targetIt)->flags;
                if (flags & 0x10000) {
                    *scoreIt += constants[82];
                } else if (flags & 0x1000) {
                    *scoreIt += constants[83];
                } else {
                    bool applies;
                    if ((flags & 0x800) &&
                        (player < 0 || player >= 8 ||
                         ((*targetIt)->playerMask & playerBit)))
                        applies = true;
                    else
                        applies = false;
                    if (applies)
                        *scoreIt += constants[84];
                }

                if ((*targetIt)->flags & 0x20)
                    *scoreIt += constants[8];
            }
        }
    }

    Target** firstTarget = targets;
    float* firstScore = scores;
    for (int i = 0; i < manager->count - 1; ++i, ++firstTarget, ++firstScore) {
        int j = i + 1;
        Target** otherTarget = targets + j;
        float* otherScore = scores + j;
        for (; j < manager->count; ++j, ++otherTarget, ++otherScore) {
            if (*otherTarget && (!*firstTarget || *firstScore > *otherScore)) {
                Target* target = *firstTarget;
                float score = *firstScore;
                *firstTarget = *otherTarget;
                *otherTarget = target;
                *firstScore = *otherScore;
                *otherScore = score;
            }
        }
    }

    Target* result = fn_27_1EFC8C(
        manager, current, excluded, targets, player, position->x, arg0, arg1);

    if (targets)
        free__13gfHeapManagerFPv(targets);
    if (scores)
        free__13gfHeapManagerFPv(scores);
    if (positions)
        free__13gfHeapManagerFPv(positions);

    return result;
}
