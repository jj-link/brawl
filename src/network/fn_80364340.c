#pragma force_active on
#include <string.h>

typedef struct Buffer { char *data; int length; int capacity; int changed; } Buffer;
extern char *fn_8035DFF8(char *, int);

static inline int reserve(Buffer *self, int capacity)
{
    char *data = fn_8035DFF8(self->data, capacity);
    if (data == 0) return 0;
    if (data != self->data) self->data = data;
    self->capacity = capacity;
    return 1;
}
static inline int append_char(Buffer *self, char c)
{
    if (self->length >= self->capacity) {
        if (!reserve(self, self->capacity + 0x400)) return 0;
    }
    self->data[self->length] = c;
    self->length++;
    return 1;
}
static inline int append(Buffer *self, const char *str)
{
    int length = strlen(str);
    if (length == 0) return 1;
    while (self->capacity - self->length <= length) {
        if (!reserve(self, self->capacity + 0x400)) return 0;
    }
    strcpy(self->data + self->length, str);
    self->length += length;
    return 1;
}
int fn_80364340(Buffer *self, const char *a, const char *b)
{
    if (!append_char(self, '<') || !append_char(self, '/') || !append(self, a) || !append_char(self, ':') || !append(self, b) || !append_char(self, '>')) return 0;
    return 1;
}