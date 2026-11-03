#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {
extern const float lbl_29_rodata_70;
extern const float lbl_29_rodata_80;
Vec2f fn_800BA0E0(int);
void fn_8003DBA8(Vec2f*);
float rsqrtf__Ff(float);
}

struct MenuEntry {
    int kind;
    float x, y;
    int unused[2];
    Vec2f position() const { return Vec2f(x, y); }
};

struct MenuRow {
    char pad[0x164];
    int indices[10];
    int count;
    int selected;
    char tail[0x94];
};

struct Menu {
    char pad[0x150];
    int state(int n) const {
        return *(int*)((char*)this + n * 0xd8 + 0x150);
    }
    Vec2f position(int n) {
        char* p = (char*)this + n * 0x14;
        return Vec2f(*(float*)(p + 0x270), *(float*)(p + 0x274));
    }
    MenuEntry* entries() {
        return (MenuEntry*)((char*)this + 0x26c);
    }
    int count() const {
        return *(int*)((char*)this + 0x334);
    }
    int occupied(int n) {
        int i;
        char* r = (char*)this;
        for (i = 0; i < 2; ++i, r += 0xd8) {
            for (int j = 0; j < ((MenuRow*)r)->count; ++j) {
                if (n == ((MenuRow*)r)->indices[j]) return 1;
            }
        }
        return 0;
    }
    int available(int row, int n) {
        if (occupied(n)) return 0;
        int i = row - 1;
        for (char* r = (char*)this + i * 0xd8; i >= 0; r -= 0xd8, --i) {
            if (n == *(int*)(r + 0x190)) return 0;
        }
        return 1;
    }
};

static inline float vectorLength(Vec2f& delta) {
    float distance = delta.m_x * delta.m_x + delta.m_y * delta.m_y;
    if ((float)(double)nw4r::ut::Abs(distance) <= lbl_29_rodata_80)
        return lbl_29_rodata_70;
    return distance * rsqrtf__Ff(distance);
}

extern "C" int fn_29_1F38(Menu* self, int row, int current) {
    float best = lbl_29_rodata_70;
    float zero;
    float distance;
    MenuEntry* entry;
    int i;
    int selected = current;
    int state = self->state(row);
    if (state == 8) return current;

    Vec2f direction = fn_800BA0E0(state);
    Vec2f delta;
    Vec2f origin = self->position(current);
    Vec2f position;
    zero = best;
    entry = self->entries();
    i = 0;
    for (; i < self->count(); ++entry, ++i) {
        if (i != current && self->available(row, i)) {
            position = entry->position();
            delta = position - origin;
            distance = vectorLength(delta);
            if (distance <= zero) continue;
            fn_8003DBA8(&delta);
            float dot = direction.m_x * delta.m_x + direction.m_y * delta.m_y;
            if (dot <= zero) continue;
            float score = dot / distance;
            if (score > best) {
                selected = i;
                best = score;
            }
        }
    }
    return selected;
}
