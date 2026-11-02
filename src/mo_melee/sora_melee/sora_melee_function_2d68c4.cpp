#pragma force_active on

struct Entry {
    Entry* prev;
    Entry* next;
    unsigned short pad;
    unsigned short count;
    int pad2[2];
};

struct Pool {
    char pad[0x518];
    Entry* cur;
    Entry* head;
    Entry* tail;
};

extern "C" void fn_27_2D68C4(Pool* self, int* idx) {
    if (*idx < 0) {
        return;
    }
    Entry* e = (Entry*)((char*)self + *idx * 0x14);
    if (e->count == 0) {
        Entry* p = self->head;
        while (p != 0) {
            p = p->next;
        }
    }
    e->count--;
    if (e->count == 0) {
        if (self->head == 0) {
            self->tail = e;
            self->head = e;
            e->next = 0;
            e->prev = 0;
        } else {
            self->tail->next = e;
            e->prev = self->tail;
            e->next = 0;
            self->tail = e;
        }
        if (self->cur != 0) {
            if (self->cur == e) {
                self->cur = 0;
            }
        }
    }
    *idx = -1;
}
