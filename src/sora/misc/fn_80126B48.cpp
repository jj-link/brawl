#include <mt/mt_vector.h>

#pragma force_active on

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
    virtual unsigned long long slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual float slot15();
    virtual float slot16();
};

typedef Vec2f V2;

struct Bounds {
    V2 a, b, c, d, e;
};

struct Info {
    char pad[8];
    int kind;
};

struct Obj {
    char p0[0x18];
    Info* info;
    char p1[0x2a0];
    Object_vptr_0* obj;
    char p2[0x24];
    float x, y;
    char p3[0x84];
    Bounds bounds;
    char p4[0xc4];
    V2 left, right;
    char p5[4];
    float top;
    char p6[4];
    float bottom;
};

extern "C" const float lbl_805A29E8, lbl_805A29EC;
extern "C" void fn_801260DC(Obj*, unsigned long long*, V2*);
extern "C" void fn_80126A80(Obj*, Bounds*);

extern "C" void fn_80126B48(Obj* p) {
    float w = p->right.m_x - p->left.m_x;
    float h = p->top - p->bottom;
    float width = p->obj->slot16();
    float height = p->obj->slot15();
    float lowx = p->bounds.d.m_x, highx = p->bounds.e.m_x;
    float highy = p->bounds.b.m_y, lowy = p->bounds.c.m_y;

    if (p->x <= lowx)
        p->x = lbl_805A29E8 + lowx;
    else if (highx <= p->x)
        p->x = highx - lbl_805A29E8;

    if (p->y <= lowy)
        p->y = lbl_805A29E8 + lowy;
    else if (highy <= p->y)
        p->y = highy - lbl_805A29E8;

    Bounds* b = &p->bounds;
    V2 size;
    unsigned long long pos = p->obj->slot8();
    fn_801260DC(p, &pos, &size);

    if (width < w) {
        if (w <= size.m_x - lbl_805A29EC) {
            b->e = b->a + p->right;
            b->d = b->a + p->left;
        } else {
            fn_80126A80(p, b);
        }
    } else {
        if (w <= size.m_x - lbl_805A29EC) {
            b->e = b->a + p->right;
            b->d = b->a + p->left;
        } else {
            fn_80126A80(p, b);
        }
    }

    if (height < h) {
        if (h <= size.m_y - lbl_805A29EC) {
            if ((p->info->kind >> 24) == 1) {
                float bottom = p->bottom;
                float top = p->top;
                b->a.m_y = b->c.m_y - bottom;
                b->e.m_y = b->a.m_y;
                b->b.m_y = b->a.m_y + top;
                b->d.m_y = b->a.m_y;
            } else {
                float y = b->a.m_y;
                float top = p->top;
                float bottom = p->bottom;
                b->e.m_y = y;
                b->d.m_y = y;
                b->c.m_y = y + bottom;
                b->b.m_y = y + top;
            }
        }
    } else {
        float bottom = p->bottom;
        float top = p->top;
        b->a.m_y = b->c.m_y - bottom;
        b->e.m_y = b->a.m_y;
        b->b.m_y = b->a.m_y + top;
        b->d.m_y = b->a.m_y;
    }
}
