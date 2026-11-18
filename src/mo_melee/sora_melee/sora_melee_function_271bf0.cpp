#include <types.h>
#include <sr/sr_common.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

class Class_C80 { public: virtual void fn_27_FEE4(int); };

extern "C" {
extern const float lbl_27_rodata_4480;
extern const float lbl_27_rodata_4484;
}

struct Entry {
    Class_C80* owner;
    Vec2f pos;
    float radius;
    int param;
    char pad[8];
    unsigned char active;
    Vec2f position() const { return pos; }
};

struct Node {
    Node* prev;
    Node* next;
    Entry* entry;
    Node() : prev(0), next(0) {}
    ~Node() {}
};

struct State {
    char pad0[8];
    Node* head;
    Node* tail;
    Node* cursor;
    unsigned int count;
    int unk18;
    unsigned char active;
    char pad1[7];
    Node* head2;
    Node* tail2;
    Node* cursor2;
    unsigned int count2;
    int unk34;
    unsigned char active2;
    char pad2[3];
    Node* hits;
    Node* hitsTail;
    Node* hitsCursor;
    unsigned int hitsCount;
};

static inline bool intersects(Vec2f& d, float rb, const Vec2f& b, float ra, const Vec2f& a) {
    float x = a.m_x - b.m_x;
    float y = a.m_y - b.m_y;
    d.m_x = x;
    d.m_y = y;
    float xSq = d.m_x * d.m_x;
    float ySq = d.m_y * d.m_y;
    float sq = xSq + ySq;
    float length;
    if ((float)(double)nw4r::ut::Abs(sq) <= lbl_27_rodata_4484)
        length = lbl_27_rodata_4480;
    else
        length = sq * rsqrtf(sq);
    if (ra + rb > length) return true;
    return false;
}

extern "C" void fn_27_271BF0(State* self) {
    Entry* a;
    Entry* b;
    if (self->active == 0 || self->active2 == 0)
        return;
        self->cursor = self->head;
        unsigned int count = self->count;
        unsigned int count2 = self->count2;
        for (unsigned int i = 0; i < count; ++i) {
            a = self->cursor->entry;
            if (a->active) {
                self->cursor2 = self->head2;
                for (unsigned int j = 0; j < count2; ++j) {
                    b = self->cursor2->entry;
                    if (b->active) {
                        Vec2f d;
                        if (intersects(d, b->radius, b->position(), a->radius, a->position())) {
                            if (!self->hits) {
                                Node* n = new (Heaps::StageInstance) Node;
                                self->hitsCursor = n;
                                self->hitsTail = n;
                                self->hits = n;
                                n->entry = b;
                            } else {
                                self->hitsTail->next = new (Heaps::StageInstance) Node;
                                self->hitsTail->next->entry = b;
                                self->hitsTail->next->prev = self->hitsTail;
                                self->hitsTail = self->hitsTail->next;
                            }
                            ++self->hitsCount;
                        }
                    }
                    self->cursor2 = self->cursor2->next;
                }
            }
            self->cursor = self->cursor->next;
        }
        self->hitsCursor = self->hits;
        unsigned int n = self->hitsCount;
        for (unsigned int i = 0; i < n; ++i) {
            Entry* e = self->hitsCursor->entry;
            e->owner->fn_27_FEE4(e->param);
            self->hitsCursor = self->hitsCursor->next;
        }
        self->hitsCursor = self->hits;
        unsigned int j = 0;
        unsigned int m = self->hitsCount;
        for (; j < m; ++j) {
            Node* p = self->hitsCursor;
            self->hitsCursor = p->next;
            delete p;
        }
        self->hits = 0;
        self->hitsTail = 0;
        self->hitsCursor = 0;
        self->hitsCount = 0;
}

