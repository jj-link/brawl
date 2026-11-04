#include <gr/collision/gr_collision_handle.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Point {
    float x, y;
};

struct Segment {
    Point a, b;
    float extra;
};

struct Node {
    char pad[15];
    unsigned char flags;
};

struct Object {
    char pad[8];
    grCollisionHandle handle;
    Node* first;
    Node* last;
    Node* end;
};

extern "C" {
extern float lbl_27_rodata_2BA4;

void fn_80111968(void*, Segment*, Node*, int);
Node* fn_80111B70(void*, Node*);
Node* fn_80111B94(void*, Node*);
unsigned int fn_27_1ED788(Point*, Point*, Point*, Point*, int);

int fn_27_1ED05C(Object* a, Object* b, Point* min, Point* max) {
    void* ownerA;
    void* ownerB;
    Node* next;
    Node* p = a->first;
    int wrapped = 0;

    if (!a->handle.isValid() || !b->handle.isValid())
        return 0;

    ownerA = *(void**)&a->handle;
    ownerB = *(void**)&b->handle;
    float epsilon = lbl_27_rodata_2BA4;

    do {
        if (p->flags & 1) {
            Segment s;
            Point left, right;

            fn_80111968(ownerA, &s, p, 0);
            if (s.a.x <= s.b.x) {
                left = s.a;
                right = s.b;
            } else {
                right = s.a;
                left = s.b;
            }

            if (!(left.x > max->x) && !(right.x < min->x) &&
                (!(left.y > max->y) || !(right.y > max->y)) &&
                (!(left.y < min->y) || !(right.y < min->y))) {
                if (nw4r::ut::Abs(left.y - right.y) < epsilon) {
                    if (left.y < min->y || left.y > max->y)
                        goto nextA;
                } else if (nw4r::ut::Abs(left.x - right.x) < epsilon) {
                    if (left.x < min->x || left.x > max->x)
                        goto nextA;
                }

                Node* q = b->first;
                int wrappedB = 0;

                do {
                    if (q->flags & 1) {
                        Segment t;
                        Point leftB, rightB;

                        fn_80111968(ownerB, &t, q, 0);
                        if (t.a.x <= t.b.x) {
                            leftB = t.a;
                            rightB = t.b;
                        } else {
                            rightB = t.a;
                            leftB = t.b;
                        }

                        if (!(left.x > rightB.x) && !(right.x < leftB.x) &&
                            fn_27_1ED788(&left, &right, &leftB, &rightB, 0) == 1)
                            return 1;
                    }

                    Node* next;
                    if (!wrappedB) {
                        if (q == b->last) {
                            if (b->first == b->end)
                                next = 0;
                            else {
                                next = fn_80111B70(ownerB, b->first);
                                wrappedB = 1;
                            }
                        } else {
                            next = fn_80111B94(ownerB, q);
                        }
                    } else if (q == b->end) {
                        next = 0;
                    } else {
                        next = fn_80111B70(ownerB, q);
                    }
                    q = next;
                } while (q);
            }
        }

    nextA:
        if (!wrapped) {
            if (p == a->last) {
                if (a->first == a->end)
                    next = 0;
                else {
                    next = fn_80111B70(ownerA, a->first);
                    wrapped = 1;
                }
            } else {
                next = fn_80111B94(ownerA, p);
            }
        } else if (p == a->end) {
            next = 0;
        } else {
            next = fn_80111B70(ownerA, p);
        }
        p = next;
    } while (p);

    return 0;
}
}
