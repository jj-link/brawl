#include <string.h>
#pragma force_active on

struct Arr {
    int count;
    int pad;
    int elem_size;
    int pad2;
    void (*func)(void*);
    char* base;
};

void fn_8035AA08(struct Arr* self, void* src, int index) {
    void* ptr;
    if (self->func != NULL) {
        if (index < 0 || index >= self->count) {
            ptr = NULL;
        } else {
            ptr = self->base + self->elem_size * index;
        }
        self->func(ptr);
    }

    if (index < 0 || index >= self->count) {
        ptr = NULL;
    } else {
        ptr = self->base + self->elem_size * index;
    }
    memcpy(ptr, src, self->elem_size);
}
