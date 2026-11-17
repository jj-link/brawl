#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma fp_contract off

struct Vec2 {
    float x;
    float y;
};

struct Segment {
    Vec2 a;
    Vec2 b;
    float extra;
};

struct Node {
    u8 pad[0xF];
    u8 flags;
};

struct Bucket {
    Bucket* next;
    u8 pad04[4];
    void* owner;
    u8 pad0C[4];
    Node* first;
    Node* last;
    Node* end;
};

struct Entry {
    u8 pad00[0x14];
    float f14;
    Vec2 min;
    Vec2 max;
    float f28;
    float f2C;
    u8 pad30[0x0E];
    u8 playerMask;
    u8 type;
    u32 flags;
    Bucket* buckets;
    u8 pad48[4];
};

struct Manager {
    u8 pad00[0x34C];
    Entry* entries;
    u16 count;
};

extern "C" {
extern const float lbl_27_rodata_2B80[];
int fn_27_1ED404(void*, Vec2*, Vec2*, int, int, int, float);
void fn_80111968(void*, Segment*, Node*, int);
Node* fn_80111B70(void*, Node*);
Node* fn_80111B94(void*, Node*);
int isValid__17grCollisionHandleFv(void*);
}

extern "C" int fn_27_1ED8A4(Manager* manager, Vec2* pos, Entry** arg2, Entry** arg3,
                            int arg4, float farg0, float farg1, float farg2)
{
    const float* const c = lbl_27_rodata_2B80;
    Segment seg;
    Vec2 r;
    Vec2 left;
    Vec2 right;
    Vec2 q;
    double d50;
    double d48;
    double d40;
    float v20;
    float v74;
    float v73;
    float v72;
    float v21;
    float v71;
    float v2;
    float v69;
    float v68;
    float v67;
    float v51;
    float v15;
    float v33;
    float v66;
    float v46;
    int bit;
    Entry* best;
    int i;
    Entry* ent;
    int flag;

    d48 = c[70];
    v66 = c[66];
    d40 = c[4];
    v46 = c[46];
    ent = manager->entries;
    bit = 1 << arg4;
    v20 = c[20];
    best = 0;
    v2 = c[2];
    i = 0;
    v21 = c[21];
    v67 = c[67];
    v51 = c[51];
    v15 = c[15];
    v33 = c[33];
    v69 = c[69];
    v68 = c[68];
    v73 = c[73];
    v72 = c[72];
    v71 = c[71];
    d50 = c[75];
    v74 = c[74];

    for (; i < manager->count; i++, ent++) {
        if (!(ent->flags & 2))
            continue;
        if (arg3 != 0) {
            float sq;
            flag = 0;
            if (pos->x < ent->min.x) {
                r = ent->min;
                r.x -= v21;
            } else if (pos->x > ent->max.x) {
                r = ent->max;
                r.x += v21;
            } else if (pos->x < v33 * (ent->min.x + ent->max.x)) {
                r = ent->min;
                r.x -= v21;
            } else {
                r = ent->max;
                r.x += v21;
            }
            if (r.y > pos->y) {
                r.y -= v33;
                float py = pos->y;
                q.x = pos->x;
                q.y = py;
                int result = fn_27_1ED404(manager, &q, &r, 0xFF, 0, 0, py);
                if ((u32)(-result | result) >> 31)
                    flag = 1;
            }
            r.x -= pos->x;
            r.y -= pos->y;
            sq = r.x * r.x + r.y * r.y;
            if (r.y > v2) {
                u32 flags = ent->flags;
                if (flags & 0x1000) {
                    sq += v15 * (r.y * r.y);
                } else {
                    int apply;
                    if ((flags & 0x800) &&
                        (arg4 < 0 || arg4 >= 8 || (ent->playerMask & bit)))
                        apply = 1;
                    else
                        apply = 0;
                    if (apply)
                        sq += v51 * (r.y * r.y);
                    else
                        sq += v67 * (r.y * r.y);
                }
                if (farg2 < v68)
                    sq += v69;
            } else {
                u32 flags = ent->flags;
                if (flags & 0x1000) {
                    sq += (float) d40 * (r.y * r.y);
                } else {
                    int apply;
                    if ((flags & 0x800) &&
                        (arg4 < 0 || arg4 >= 8 || (ent->playerMask & bit)))
                        apply = 1;
                    else
                        apply = 0;
                    if (apply)
                        sq += (float) d48 * (r.y * r.y);
                }
            }
            {
                u32 flags = ent->flags;
                if (flag) {
                    if (r.x > v2) {
                        if (!(flags & 0x40))
                            sq *= v71;
                        else
                            sq *= v69;
                    } else {
                        if (!(flags & 0x80))
                            sq *= v71;
                        else
                            sq *= v69;
                    }
                } else if (pos->x < ent->min.x) {
                    if (nw4r::ut::Abs(r.y) > v21)
                        sq += nw4r::ut::Abs(r.x) / nw4r::ut::Abs(r.y);
                    else
                        sq += nw4r::ut::Abs(r.x);
                    if (!(flags & 0x40))
                        sq *= v72;
                } else if (pos->x > ent->max.x) {
                    if (nw4r::ut::Abs(r.y) > v21)
                        sq += nw4r::ut::Abs(r.x) / nw4r::ut::Abs(r.y);
                    else
                        sq += nw4r::ut::Abs(r.x);
                    if (!(flags & 0x80))
                        sq *= v72;
                } else if (r.y > v2) {
                    if (r.x > v2) {
                        if (!(flags & 0x40))
                            sq *= v73;
                    } else {
                        if (!(flags & 0x80))
                            sq *= v73;
                    }
                }
                if ((flags & 0x20000) && (ent->f14 < v74))
                    sq += (float) d50;
            }
            if (v46 < v68 || v46 > sq) {
                v46 = sq;
                *arg3 = ent;
            }
        }
        if (pos->x < ent->min.x || pos->x > ent->max.x || pos->y < ent->f28 ||
            ent->f2C < farg0)
            continue;
        if ((ent->flags & 0x20000) && (ent->f14 < v74))
            continue;
        float y;
        if (ent->type == 3) {
            Bucket* b;
            void* owner;
            Node* node;
            Node* next;
            for (b = ent->buckets; b != 0; b = b->next) {
                node = b->first;
                flag = 0;
                if (!isValid__17grCollisionHandleFv(&b->owner))
                    continue;
                owner = b->owner;
                do {
                    if (node->flags & 1) {
                        fn_80111968(owner, &seg, node, 0);
                        if (seg.a.x <= seg.b.x) {
                            left = seg.a;
                            right = seg.b;
                        } else {
                            right = seg.a;
                            left = seg.b;
                        }
                        if (!(pos->x < left.x) && !(pos->x > right.x)) {
                            float dd = right.x - left.x;
                            if (!(dd < v20)) {
                                y = left.y + ((pos->x - left.x) / dd) * (right.y - left.y);
                                if (!(pos->y < y)) {
                                    if (arg2 == 0)
                                        return 1;
                                    if (v66 < y) {
                                        v66 = y;
                                        best = ent;
                                    }
                                }
                            }
                        }
                    }
                    if (!flag) {
                        if (node == b->last) {
                            if (b->first == b->end) {
                                next = 0;
                            } else {
                                next = fn_80111B70(owner, b->first);
                                flag = 1;
                            }
                        } else {
                            next = fn_80111B94(owner, node);
                        }
                    } else if (node == b->end) {
                        next = 0;
                    } else {
                        next = fn_80111B70(owner, node);
                    }
                    node = next;
                } while (node != 0);
            }
            continue;
        }
        {
            switch (ent->type) {
            case 1:
                y = ent->f28;
                break;
            case 2: {
                float dx = pos->x - ent->min.x;
                y = ent->min.y + (dx / (ent->max.x - ent->min.x)) * (ent->max.y - ent->min.y);
                if (pos->y < y)
                    continue;
                break;
            }
            }
            if (arg2 == 0)
                return 1;
            if (v66 < y) {
                v66 = y;
                best = ent;
            }
        }
    }
    if (arg2 != 0)
        *arg2 = best;
    return best != 0;
}
