#include <types.h>
#pragma force_active on

struct Vec2f {
    float x, y;

    Vec2f() {}

    friend Vec2f operator-(const Vec2f& a, const Vec2f& b) {
        Vec2f r;
        r.x = a.x - b.x;
        r.y = a.y - b.y;
        return r;
    }

    float lengthSq() {
        return x * x + y * y;
    }
};

struct AiQueryRecordView {
    char pad[0x28];
    Vec2f position;
};

struct AiQueryPoolView;

extern "C" AiQueryRecordView* fn_27_219188(AiQueryPoolView*);
extern const float lbl_27_rodata_31FC;

extern "C" AiQueryRecordView* fn_27_219220(AiQueryPoolView* pool, Vec2f* point) {
    float bestDistance = lbl_27_rodata_31FC;
    AiQueryRecordView* best = 0;

    for (;;) {
        AiQueryRecordView* record = fn_27_219188(pool);
        if (!record)
            break;

        Vec2f delta;
        delta.x = point->x - record->position.x;
        delta.y = point->y - record->position.y;
        float distance = delta.lengthSq();

        if (bestDistance > distance) {
            bestDistance = distance;
            best = record;
        }
    }

    return best;
}
