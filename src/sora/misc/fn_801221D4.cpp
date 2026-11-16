#include <types.h>
#include <mt/mt_vector.h>

#pragma force_active on
#pragma fp_contract off

inline void assign(Vec2f& a, const Vec2f& b) { a.m_x = b.m_x; a.m_y = b.m_y; }

struct Offset : Vec2f {
    Offset(f32 y, f32 x) : Vec2f(x, y) {}
};

struct Record {
    s32 a, b, c;
    u8 d, e;
    Record& operator=(const Record& v) {
        a = v.a; b = v.b; c = v.c; d = v.d; e = v.e;
        return *this;
    }
};

struct Source { char pad0[0x1a]; u16 count; };
struct Target {
    char pad0[8]; s32 type8;
    char pad0c[0x75 - 0xc]; u8 flags75;
    char pad76[0xd4 - 0x76];
    s32 w0d4, w0d8, w0dc; u8 b0e0, b0e1;
    char pad0e2[0xe4 - 0xe2];
    s32 w0e4, w0e8, w0ec; u8 b0f0, b0f1;
    char pad0f2[0xf4 - 0xf2];
    s32 w0f4, w0f8, w0fc; u8 b100, b101;
    char pad102[0x104 - 0x102];
    s32 w104, w108, w10c; u8 b110, b111;
    void copyRecord(const Record& v) {
        w0d4 = v.a;
        w0d8 = v.b;
        w0dc = v.c;
        b0e0 = v.d;
        b0e1 = v.e;
    }
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual Vec2f slot8();
    virtual Vec2f slot9();
    virtual Vec2f slot10();
    virtual Vec2f slot11();
    virtual Vec2f slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(Vec2f*, Vec2f*, Vec2f*);
    virtual void slot20(Vec2f*, Vec2f*, Vec2f*);
    virtual void slot21(Vec2f*, Vec2f*);
};
struct Object_vptr_32c_base {
    char pad0[0xc]; u8 flags0c;
    char pad0d[0x18 - 0xd]; Target* target; Source* source;
    char pad20[0x34 - 0x20]; u8 b34; char pad35[3]; f32 f38;
    s32 w3c, w40, w44; u8 b48, b49;
    char pad4a[0x54 - 0x4a]; s32 w54, w58, w5c; u8 b60, b61;
    char pad62[0x6c - 0x62]; s32 w6c, w70, w74; u8 b78, b79;
    char pad7a[0x224 - 0x7a]; s32 w224, w228, w22c; u8 b230, b231;
    char pad232[0x2bc - 0x232]; Object_vptr_0* shape;
    char pad2c0[0x2c8 - 0x2c0]; u8 flags2c8, flags2c9, flags2ca, flags2cb;
    char pad2cc[0x2dc - 0x2cc]; Vec2f v2dc;
    char pad2e4[0x2ec - 0x2e4]; Vec2f v2ec, v2f4, v2fc, v304;
    s32 w30c, w310, w314; u8 b318, b319;
    char pad31a[0x31c - 0x31a]; s32 w31c, w320, w324; u8 b328, b329;
    char pad32a[0x32c - 0x32a];
    void applyRecord(const u8& e, u8 mode, u8 d, s32 c, s32 b, s32 a, f32 value) {
        b34 = mode;
        f38 = value;
        w3c = a;
        w40 = b;
        w44 = c;
        b48 = d;
        b49 = e;
    }
    void setRecord(u8 mode, f32 value, const Record& record) {
        applyRecord(record.e, mode, record.d, record.c, record.b, record.a, value);
    }
};
class Object_vptr_32c : public Object_vptr_32c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};
extern "C" int fn_80122978(Object_vptr_32c*);
extern "C" int fn_80122D6C(Object_vptr_32c*);
extern "C" void fn_801340A0(void*);
extern f32 lbl_805A2960, lbl_805A297C, lbl_805A2980, lbl_805A2984, lbl_805A2994, lbl_805A29AC;

extern "C" int fn_801221D4(Object_vptr_32c* self) {
    int ret;
    if (self->source->count == 0) return 0;
    self->flags0c |= 0x40;
    self->flags2ca = 0;
    self->flags2c9 = self->flags2cb;
    assign(self->v304, self->shape->slot11());
    assign(self->v2fc, self->shape->slot10());
    assign(self->v2ec, self->shape->slot12());
    assign(self->v2f4, self->shape->slot9());
    self->v2dc.m_x = self->v304.m_x - self->v2fc.m_x;
    self->v2dc.m_y = self->v2ec.m_y - self->v2f4.m_y;
    ret = 0;
    if (fn_80122978(self)) {
        fn_80122978(self);
        ret = 1;
    }
    if ((self->flags2c9 >> 7) & 1) self->target->flags75 |= 0x10;
    if ((self->flags2c9 >> 6) & 1) self->target->flags75 |= 0x20;
    if (((self->flags2c9 >> 7) & 1) && ((self->flags2c9 >> 6) & 1) &&
        (self->v304.m_x - self->v2fc.m_x) < self->v2dc.m_x) {
        Vec2f e;
        Vec2f::copy(e, self->shape->slot8());
        if (self->v2fc.m_x < self->v304.m_x) {
            if (self->v2fc.m_x < e.m_x && e.m_x < self->v304.m_x) {
                self->shape->slot21(&self->v2fc, &self->v304);
            } else {
                f32 g = self->shape->slot11().m_x;
                f32 h = self->shape->slot10().m_x;
                f32 ratio = (e.m_x - h) / (g - h);
                e.m_x = self->v2fc.m_x + ratio * (self->v304.m_x - self->v2fc.m_x);
                if (e.m_x < self->v2fc.m_x) e.m_x = lbl_805A297C * (self->v2fc.m_x + self->v304.m_x);
                self->shape->slot19(&e, &self->v2fc, &self->v304);
            }
        } else {
            Vec2f lo, hi;
            Vec2f::copy(lo, self->v2fc);
            Vec2f::copy(hi, self->v304);
            lo.m_x = e.m_x - lbl_805A2980;
            hi.m_x = lbl_805A2980 + e.m_x;
            self->shape->slot19(&e, &lo, &hi);
        }
        Target* t = self->target;
        t->w0e4 = self->w54;
        t->w0e8 = self->w58;
        t->w0ec = self->w5c;
        t->b0f0 = self->b60;
        t->b0f1 = self->b61;
        t = self->target;
        t->w0f4 = self->w6c;
        t->w0f8 = self->w70;
        t->w0fc = self->w74;
        t->b100 = self->b78;
        t->b101 = self->b79;
        self->target->flags75 |= 0x20;
        self->target->flags75 |= 0x10;
    }
    Vec2f p, q, r;
    Vec2f::copy(p, self->shape->slot8());
    Vec2f::copy(q, self->shape->slot11());
    Vec2f::copy(r, self->shape->slot10());
    if (fn_80122D6C(self)) {
        u8 c8 = self->flags2c8;
        if (((c8 >> 4) & 1) && (((c8 >> 7) & 1) || ((c8 >> 6) & 1))) {
            Vec2f s12, z;
            Vec2f::copy(s12, self->shape->slot12());
            Vec2f::copy(z, self->shape->slot9());
            z.m_y = self->v2f4.m_y;
            self->shape->slot19(&p, &r, &q);
            if (p.m_y > s12.m_y || p.m_y < z.m_y) {
                p.m_y = lbl_805A297C * (s12.m_y + z.m_y);
            }
            self->shape->slot20(&p, &s12, &z);
        }
        fn_80122D6C(self);
        ret = 1;
    }
    if ((self->flags2c9 >> 4) & 1) {
        if ((self->target->type8 >> 24) == 2 || (self->target->type8 >> 24) == 2) {
            fn_801340A0(self->target);
            Target* t2 = self->target;
            t2->w104 = self->w31c;
            t2->w108 = self->w320;
            t2->w10c = self->w324;
            t2->b110 = self->b328;
            t2->b111 = self->b329;
            self->w224 = self->w31c;
            self->w228 = self->w320;
            self->w22c = self->w324;
            self->b230 = self->b328;
            self->b231 = self->b329;
        }
    }
    if ((self->target->type8 >> 24) == 1) self->flags2c9 |= 0x10;
    if ((self->flags2c9 >> 5) & 1) {
        bool valid = false;
        if (self->w30c != 0 && self->w310 != 0 && self->w314 != 0) valid = true;
        if (valid) {
            const Record& entry = *(Record*)&self->w30c;
            self->applyRecord(entry.e, 4, entry.d, entry.c, entry.b, entry.a, lbl_805A2960);
            self->target->copyRecord(*(Record*)&self->w30c);
            self->target->flags75 |= 0x40;
        }
    }
    if (((self->flags2c9 >> 5) & 1) && ((self->flags2c9 >> 4) & 1)) {
        f32 sum;
        f32 b;
        f32 a;
        f32 diff;
        a = self->v2ec.m_y;
        b = self->v2f4.m_y;
        sum = a + b;
        diff = a - b;
        Vec2f w;
        w.m_y = lbl_805A297C * sum;
        w.m_x = self->shape->slot8().m_x;
        if (diff > lbl_805A29AC) {
            if (diff < self->v2dc.m_y) {
                self->shape->slot20(&w, &self->v2ec, &self->v2f4);
            }
        } else {
            Vec2f p90;
            Vec2f::copy(p90, self->v2ec);
            Vec2f p88;
            Vec2f::copy(p88, self->v2f4 + Offset(lbl_805A2994, lbl_805A2960));
            w.m_y = lbl_805A2980 + p88.m_y;
            p90.m_y = lbl_805A2984 + p88.m_y;
            self->shape->slot20(&w, &p90, &p88);
        }
    }
    self->shape->slot18();
    self->slot10();
    return ret;
}
