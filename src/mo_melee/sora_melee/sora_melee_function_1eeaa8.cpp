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
Target* fn_27_1EF3AC(TargetManager*, Target*, int);
void fn_27_1EF144(TargetManager*, Target**, Point2*, float*, Target*);
int fn_27_1EFE3C(TargetManager*, Target*, Target*, int, float, float, float);
}

extern "C" Target* fn_27_1EEAA8(TargetManager* manager, Target* current,
    Target* excluded, int player, const Point2* points, int pointCount,
    Target** output, float arg0, float arg1, float arg2, float distanceScale)
{
    const float* const constants = lbl_27_rodata_2B80;
    int outputPlayerBit;
    const Point2* outputPoint;
    Target** outputTargetIt;
    float* outputScoreIt;
    int outputIndex;
    Point2* outputPositionIt;
    Target** targets = static_cast<Target**>(
        gfHeapManager::alloc(static_cast<Heaps::HeapType>(12), manager->count * 4));
    float* scores = static_cast<float*>(
        gfHeapManager::alloc(static_cast<Heaps::HeapType>(12), manager->count * 4));
    Point2* positions = static_cast<Point2*>(
        gfHeapManager::alloc(static_cast<Heaps::HeapType>(12), manager->count * 8));

    if (!targets || !scores || !positions) {
        if (targets) gfHeapManager::free(targets);
        if (scores) gfHeapManager::free(scores);
        if (positions) gfHeapManager::free(positions);
        return current;
    }
    if (!excluded)
        excluded = fn_27_1EF3AC(manager, current, player);
    fn_27_1EF144(manager, targets, positions, scores, excluded);
    if (!output) {
        Target** targetIt = targets;
        float* scoreIt = scores;
        for (int i = 0; i < manager->count; ++i, ++targetIt, ++scoreIt) {
            int valid = 0;
            if (*targetIt) {
                if (*targetIt != current)
                    valid = fn_27_1EFE3C(manager, current, *targetIt, player,
                                         arg0, arg1, arg2);
                if (!valid) {
                    *targetIt = 0;
                } else if (*scoreIt < constants[27] && distanceScale >= constants[2]) {
                    Target* result = *targetIt;
                    if (targets) gfHeapManager::free(targets);
                    if (scores) gfHeapManager::free(scores);
                    if (positions) gfHeapManager::free(positions);
                    return result;
                }
            }
        }
        float bestScore = constants[82];
        int playerBit = 1 << player;
        Target** selectionTargetIt = targets;
        float* selectionScoreIt = scores;
        int i;
        Point2* positionIt = positions;
        for (i = 0; i < manager->count;
             ++i, ++selectionTargetIt, ++selectionScoreIt, ++positionIt) {
            if (*selectionTargetIt) {
                float score = *selectionScoreIt;
                if (points) {
                    const Point2* point = points;
                    for (int j = 0; j < pointCount; ++point, ++j) {
                        Vec2f difference;
                        difference.m_x = point->x - positionIt->x;
                        difference.m_y = point->y - positionIt->y;
                        float square = difference.m_x * difference.m_x +
                                       difference.m_y * difference.m_y;
                        float distance;
                        if (static_cast<float>(static_cast<double>(nw4r::ut::Abs(square))) <= constants[28])
                            distance = constants[2];
                        else
                            distance = square * rsqrtf(square);
                        score += distanceScale * distance;
                    }
                }
                Target* target = *selectionTargetIt;
                unsigned int flags = target->flags;
                if (flags & 0x10000) {
                    score += constants[82];
                } else if (flags & 0x1000) {
                    score += constants[83];
                } else {
                    bool applies;
                    if ((flags & 0x800) &&
                        (player < 0 || player >= 8 || (target->playerMask & playerBit)))
                        applies = true;
                    else
                        applies = false;
                    if (applies)
                        score += constants[84];
                }
                if (flags & 0x20)
                    score += constants[8];
                if (bestScore > score) {
                    bestScore = score;
                    current = target;
                }
            }
        }
        if (targets) gfHeapManager::free(targets);
        if (scores) gfHeapManager::free(scores);
        if (positions) gfHeapManager::free(positions);
        return current;
    } else {
        float bestScore = constants[82];
        float fallbackScore = bestScore;
        Target* result = current;
        Target* fallback = current;
        outputPlayerBit = 1 << player;
        outputTargetIt = targets;
        outputScoreIt = scores;
        outputPositionIt = positions;
        for (outputIndex = 0; outputIndex < manager->count;
             ++outputIndex, ++outputTargetIt, ++outputScoreIt, ++outputPositionIt) {
            int valid = 0;
            if (*outputTargetIt) {
                float score = *outputScoreIt;
                if (*outputTargetIt != current)
                    valid = fn_27_1EFE3C(manager, current, *outputTargetIt, player,
                                         arg0, arg1, arg2);
                if (valid && score < constants[27] && distanceScale >= constants[2]) {
                    result = *outputTargetIt;
                    break;
                }
                if (points) {
                    outputPoint = points;
                    for (int j = 0; j < pointCount; ++outputPoint, ++j) {
                        Vec2f difference;
                        difference.m_x = outputPoint->x - outputPositionIt->x;
                        difference.m_y = outputPoint->y - outputPositionIt->y;
                        float square = difference.m_x * difference.m_x +
                                       difference.m_y * difference.m_y;
                        float distance;
                        if (static_cast<float>(static_cast<double>(nw4r::ut::Abs(square))) <= constants[28])
                            distance = constants[2];
                        else
                            distance = square * rsqrtf(square);
                        score += distanceScale * distance;
                    }
                }
                Target* target = *outputTargetIt;
                unsigned int flags = target->flags;
                if (flags & 0x20)
                    score += constants[8];
                if (flags & 0x10000) {
                    score += constants[82];
                } else if (flags & 0x1000) {
                    score += constants[83];
                } else {
                    bool applies;
                    if ((flags & 0x800) &&
                        (player < 0 || player >= 8 || (target->playerMask & outputPlayerBit)))
                        applies = true;
                    else
                        applies = false;
                    if (applies)
                        score += constants[84];
                }
                if (valid && bestScore > score) {
                    bestScore = score;
                    result = target;
                }
                if (fallbackScore > score) {
                    fallbackScore = score;
                    fallback = target;
                }
            }
        }
        *output = fallback;
        if (targets) gfHeapManager::free(targets);
        if (scores) gfHeapManager::free(scores);
        if (positions) gfHeapManager::free(positions);
        return result;
    }
}
