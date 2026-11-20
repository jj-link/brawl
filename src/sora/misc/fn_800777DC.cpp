#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
extern const float lbl_805A1AC8;
extern const float lbl_805A1ACC;
}

class Sub {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void fn6();
    virtual void fn7();
    virtual void fn8();
    virtual void fn9();
    virtual void fn10();
    virtual void fn11();
    virtual void fn12(int, float);
};

struct Entry {
    Sub* object;
    int id;
    int unk8;
    u32 handle;
    char pad[12];
    u16 count;
    u16 unk1E;

    bool active() const {
        return handle != (u32)-1 && count != 0;
    }

    bool present() const {
        if (active())
            return true;
        return object != 0;
    }
};

struct System {
    char pad[0x2D4];
    Entry entries[32];
    char pad2[0x38];
    float m_val;
    char pad3[8];
    float m_mult;

    u32 index(int id) {
        if (id == -1)
            return -1;

        bool valid = false;
        u32 slot = (u8)id;
        Entry* entry = &entries[slot];

        if (entry->id == id) {
            if (entry->present())
                valid = true;
        }

        return valid ? slot : (u32)-1;
    }
};

inline float limitUpper(float value, float upper) {
    return nw4r::math::FSelect(upper - value, value, upper);
}
inline float clamp(float value, float lower, float upper) {
    float clamped = limitUpper(value, upper);
    return nw4r::math::FSelect(lower - clamped, lower, clamped);
}

extern "C" void fn_800777DC(System* self, int id, float value, int arg) {
    float delta;
    u32 slot = self->index(id);
    if (slot == (u32)-1)
        return;

    Entry* entry = &self->entries[slot];
    float one = lbl_805A1AC8;
    float t = clamp(value, (lbl_805A1ACC), one);
    float r = self->m_val * (t * self->m_mult);
    if (entry->object != 0)
        entry->object->fn12(arg, r);
}
