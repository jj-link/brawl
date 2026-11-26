#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_450;
extern "C" const float lbl_27_rodata_454;

struct Info {
    void* line;
    void* data;
    void* collision;
    u8 tail;
    u8 high : 1;
    u8 rest : 7;
};

struct Id {
    u32 v;
};

struct Self {
    u8 pad0[8];
    Id id0;
    Id id1;
    u8 pad1[4];
    Vec2f position;
};

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" Vec2f fn_80114E9C(void*);
extern "C" Vec2f fn_80114DAC(void*, Vec2f*);
extern "C" void fn_8003DBA8(Vec2f*);
extern "C" float fn_8003DDD0(Vec2f*, Vec2f*);
extern "C" double sin(double);

inline bool sameNormal(Info* first, Info* second) {
    Vec2f p1;
    Vec2f::copy(p1, fn_80114E9C(first));
    Vec2f p2;
    Vec2f::copy(p2, fn_80114E9C(second));
    fn_8003DBA8(&p1);
    fn_8003DBA8(&p2);
    Vec2f d;
    Vec2f::copy(d, p1 - p2);
    return d.lengthSq() <= lbl_27_rodata_454;
}

inline bool enabled(Info& info) {
    int valid = 0;
    if (info.line && info.data && info.collision) valid = 1;
    if (valid && ((*(u8*)((char*)info.data + 0x54) >> 4) & 1) &&
        ((*(u8*)((char*)info.collision + 0x2c) >> 7) & 1))
        return true;
    return false;
}
inline bool sameNormalIfEnabled(Info& first, Info& second) {
    if (!enabled(first)) return false;
    if (!enabled(second)) return false;
    Vec2f p1;
    Vec2f::copy(p1, fn_80114E9C(&first));
    Vec2f p2;
    Vec2f::copy(p2, fn_80114E9C(&second));
    fn_8003DBA8(&p1);
    fn_8003DBA8(&p2);
    return (p1 - p2).lengthSq() <= lbl_27_rodata_454;
}

inline bool isFacing(Info* first, Info* second, Vec2f* position) {
    Vec2f q;
    Vec2f::copy(q, fn_80114DAC(first, position));
    Vec2f d;
    Vec2f::copy(d, *position - q);
    Vec2f w;
    Vec2f::copy(w, fn_80114E9C(second));
    fn_8003DBA8(&d);
    fn_8003DBA8(&w);
    return (d.m_x * w.m_x + d.m_y * w.m_y) >= lbl_27_rodata_450;
}

inline bool facingIfEnabled(Info& first, Info& second, Vec2f& position) {
    if (!enabled(first)) return false;
    if (!enabled(second)) return true;
    Vec2f q;
    Vec2f::copy(q, fn_80114DAC(&first, &position));
    Vec2f d;
    Vec2f::copy(d, position - q);
    Vec2f w;
    Vec2f::copy(w, fn_80114E9C(&second));
    fn_8003DBA8(&d);
    fn_8003DBA8(&w);
    return (d.m_x * w.m_x + d.m_y * w.m_y) >= lbl_27_rodata_450;
}

extern "C" Vec2f fn_27_312B0(Self* self, f32 t) {
    if (t <= lbl_27_rodata_450) {
        return Vec2f(lbl_27_rodata_450, lbl_27_rodata_450);
    }

    Vec2f a;
    Vec2f b;
    Vec2f out;
    Vec2f q;
    Vec2f finalDelta;
    int valid = 0;
    Info info;
    info.line = 0;
    info.data = 0;
    info.collision = 0;
    info.tail = 0;
    info.high = 0;

    int ok;
    if (self->id0.v == 0xFFFF) {
        ok = 0;
    } else {
        Id id;
        id = self->id0;
        if (fn_80111CB0(&id, &info) == 0) {
            ok = 0;
        } else {
            if (info.line && info.data && info.collision) valid = 1;
            int enabled;
            if (valid && ((*(u8*)((char*)info.data + 0x54) >> 4) & 1) &&
                ((*(u8*)((char*)info.collision + 0x2c) >> 7) & 1))
                enabled = 1;
            else
                enabled = 0;
            ok = enabled != 0;
        }
    }
    if (!ok) {
        return Vec2f(lbl_27_rodata_450, lbl_27_rodata_450);
    }

    int valid2 = 0;
    u32 both = 1;
    Info info2;
    info2.line = 0;
    info2.data = 0;
    info2.collision = 0;
    info2.tail = 0;
    info2.high = 0;

    int ok2;
    if (self->id1.v == 0xFFFF) {
        ok2 = 0;
    } else {
        Id id;
        id = self->id1;
        if (fn_80111CB0(&id, &info2) == 0) {
            ok2 = 0;
        } else {
            if (info2.line && info2.data && info2.collision) valid2 = 1;
            int enabled;
            if (valid2 && ((*(u8*)((char*)info2.data + 0x54) >> 4) & 1) &&
                ((*(u8*)((char*)info2.collision + 0x2c) >> 7) & 1))
                enabled = 1;
            else
                enabled = 0;
            ok2 = enabled != 0;
        }
    }

    if (!ok2) both = 0;

    a.m_x = lbl_27_rodata_450;
    a.m_y = lbl_27_rodata_450;
    b.m_x = lbl_27_rodata_450;
    b.m_y = lbl_27_rodata_450;
    if (both == 1) {
        a = fn_80114E9C(&info);
        b = fn_80114E9C(&info2);
    } else {
        a = fn_80114E9C(&info);
    }
    fn_8003DBA8(&a);
    fn_8003DBA8(&b);

    int collinear = 0;
    int facing = 0;
    if (both == 1) {
        collinear = sameNormalIfEnabled(info, info2);

        facing = facingIfEnabled(info, info2, self->position);
    }

    out.m_x = lbl_27_rodata_450;
    out.m_y = lbl_27_rodata_450;
    if (both == 1 && collinear == 0) {
        out = a + b;
        fn_8003DBA8(&out);
        if (facing == 0) {
            Vec2f::copy(q, fn_80114DAC(&info, &self->position));
            Vec2f::copy(finalDelta, q - self->position);
            t = t / (f32)sin(fn_8003DDD0(&out, &finalDelta));
        }
    } else {
        out.m_x = a.m_x;
        out.m_y = a.m_y;
        fn_8003DBA8(&out);
    }
    out.m_x *= t;
    out.m_y *= t;
    return out;
}
