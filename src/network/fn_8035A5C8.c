#include <string.h>
#pragma force_active on

struct Arr {
    int count;
    int capacity;
    int elem_size;
    int growth;
    void (*func)(void*);
    char* base;
};

extern char* fn_8035DFF8(char*, int);
extern void* fn_803F602C(void*, const void*, unsigned int);

void fn_8035A5C8(struct Arr* self, void* src) {
    int index;
    int end;
    void* dest;
    void* from;

    if (self != NULL) {
        index = self->count;
        if (index == self->capacity) {
            self->capacity += self->growth;
            self->base = fn_8035DFF8(self->base, self->capacity * self->elem_size);
        }
        self->count++;
        end = self->count - 1;
        if (index < end) {
            if (index + 1 < 0 || index + 1 >= self->count) {
                dest = NULL;
            } else {
                dest = self->base + self->elem_size * (index + 1);
            }
            if (index < 0 || index >= self->count) {
                from = NULL;
            } else {
                from = self->base + self->elem_size * index;
            }
            fn_803F602C(dest, from, self->elem_size * (end - index));
        }
        if (index < 0 || index >= self->count) {
            dest = NULL;
        } else {
            dest = self->base + self->elem_size * index;
        }
        memcpy(dest, src, self->elem_size);
    }
}
