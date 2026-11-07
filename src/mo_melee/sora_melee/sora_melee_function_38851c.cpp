#include <types.h>
#pragma force_active on

struct Segment {
    float a;
    float pad4;
    float c;
    float padc;
};

struct Node {
    unsigned char pad[0xf];
    unsigned char flags;
};

extern "C" int isValid__17grCollisionHandleFv(void*);
extern "C" void fn_80111968(void*, Segment*, Node*, int);
extern "C" Node* fn_80111B70(void*, Node*);
extern "C" Node* fn_80111B94(void*, Node*);

struct Entry {
    Entry* next;
    int pad4;
    void* owner;
    int padc;
    Node* first;
    Node* last;
    Node* end;
};

struct Holder {
    unsigned char pad[0x44];
    Entry* list;
};

extern "C" void fn_27_38851C(void* self, Holder* h, float* ref, float* maxOut, float* minOut) {
    Segment seg;
    for (Entry* e = h->list; e != 0; e = e->next) {
        if (isValid__17grCollisionHandleFv(&e->owner)) {
            void* owner = e->owner;
            Node* n = e->first;
            int wrapped = 0;
            while (n != 0) {
                unsigned char f = n->flags;
                if ((u32)(f & 1) == 1 && !((f >> 6) & 1)) {
                    fn_80111968(owner, &seg, n, 0);
                    if (seg.c <= *ref) {
                        if (*maxOut < seg.c) *maxOut = seg.c;
                    } else if (seg.a >= *ref) {
                        if (*minOut > seg.a) *minOut = seg.a;
                    }
                }
                Node* next;
                if (wrapped == 0) {
                    if (n == e->last) {
                        if (e->first == e->end) {
                            next = 0;
                        } else {
                            next = fn_80111B70(owner, e->first);
                            wrapped = 1;
                        }
                    } else {
                        next = fn_80111B94(owner, n);
                    }
                } else if (n == e->end) {
                    next = 0;
                } else {
                    next = fn_80111B70(owner, n);
                }
                n = next;
            }
        }
    }
}
