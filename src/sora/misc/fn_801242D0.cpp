#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Class_8042EA48 {
public:
    virtual void fn_8005C534();
    virtual void fn_8005C2B0();
    virtual void fn_8005C20C();
    virtual void fn_8005C1BC();
    virtual void fn_8005C198();
    virtual void fn_8005C17C();
    virtual void fn_8005C160(const Vec2f&);
    virtual void fn_8005C0BC();
    virtual Vec2f fn_8005C06C();
    virtual void fn_8005C048();
    virtual Vec2f fn_8005C02C();
    virtual Vec2f fn_8005C010();
    virtual void fn_8005BF6C();
    virtual void fn_8005BF1C();
    virtual void fn_8005BEF8(Class_8042EA48&);
    virtual void fn_8005BEDC();
    virtual void fn_8005BEC0();
    virtual void fn_8005BE1C();
    virtual void fn_8005BDCC();
    virtual void fn_8005BDA8(const Vec2f&, const Vec2f&, const Vec2f&);
};

struct Entry { u8 data[0x10]; };
struct Class_8045DA20_base {
    u8 pad0[8];
    float value;
    u8 flags0 : 4;
    u8 changed : 1;
    u8 flags1 : 3;
    u8 flagsD;
    u8 padE[0x18 - 0xE];
    void* owner;
    u8 pad1C[0x7C - 0x1C];
    u8 state7C;
    u8 pad7D[0xF4 - 0x7D];
    u8 stateF4;
    u8 padF5[0x11C - 0xF5];
    u16 count;
    u8 pad11E[2];
    Entry entries[0x19];
    u8 pad2B0[0xC];
    Class_8042EA48* shape;
    Class_8042EA48* shape2;
    Class_8042EA48* shape3;
    u8 pad2C8[0x32C-0x2C8];
};
class Class_8045DA20 : public Class_8045DA20_base {
public:
    virtual void fn_80125930();
    virtual void fn_80125E1C(float);
};
extern "C" int fn_80124594(Class_8045DA20*);
extern "C" void fn_80124080(Class_8045DA20*);
extern "C" int fn_80137074(void*, const Entry*);
extern float lbl_805A295C;
extern float lbl_805A2960;
extern float lbl_805A2994;
extern float lbl_805A29B0;
extern float lbl_805A29B4;
extern float lbl_805A29B8;
extern "C" int fn_801242D0(Class_8045DA20* self) {
    float initial = lbl_805A295C;
    self->count = 0;
    self->value = initial;
    self->changed = 0;
    int limit;
    int result = fn_80124594(self);
    limit = 2;
    u32 state = self->stateF4;
    while (state != 0xFF) {
        if ((self->flagsD & 0xC0) == 0xC0) {
            Vec2f center, left, right;
            Vec2f::copy(center, self->shape->fn_8005C06C());
            Vec2f::copy(left, self->shape->fn_8005C02C());
            Vec2f::copy(right, self->shape->fn_8005C010());
            if (center.m_x - left.m_x > lbl_805A29B4) {
                left.m_x = center.m_x + lbl_805A29B0 * (left.m_x - center.m_x);
            }
            if (right.m_x - center.m_x > lbl_805A29B4) {
                right.m_x = center.m_x + lbl_805A29B0 * (right.m_x - center.m_x);
            }
            self->shape->fn_8005BDA8(center, left, right);
            center = self->shape3->fn_8005C06C();
            self->shape2->fn_8005BEF8(*self->shape);
            self->shape2->fn_8005C160(center);
            if (fn_80124594(self)) result = 1;
            break;
        } else {
            if (state > 3U) {
                if (fn_80124594(self)) result = 1;
                state = self->stateF4;
            }
            if (--limit <= 0) break;
        }
    }
    if (self->changed) {
        self->shape3->fn_8005BEF8(*self->shape2);
    }
    if (self->state7C == 0xFF) {
        Entry* entry;
        u16 count = self->count;
        entry = self->entries;
        for (u32 i = 0; i < count; ++entry, ++i) {
            fn_80137074(self->owner, entry);
        }
        self->count = 0;
    }
    if (result) {
        if (self->value < lbl_805A2994) self->value = lbl_805A2960;
        if (self->value > lbl_805A2960) self->fn_80125E1C(lbl_805A29B8 * self->value);
        fn_80124080(self);
        if (self->value < lbl_805A295C) result = 1;
    }
    return result;
}
