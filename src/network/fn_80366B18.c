#pragma force_active on
#include <string.h>
#include <internal/printf.h>

typedef struct { char *data; int length; int capacity; int changed; } Buffer;

extern char *fn_8035DFF8(char *, int);
extern int *fn_8035D7B0(int *);
extern const char lbl_8048E9E8[];

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

static inline int open_tag(Buffer *self, const char *a, const char *b)
{
    if (!append_char(self, '<') || !append(self, a) || !append_char(self, ':') || !append(self, b) || !append_char(self, '>')) return 0;
    return 1;
}

static inline int close_tag(Buffer *self, const char *a, const char *b)
{
    if (!append_char(self, '<') || !append_char(self, '/') || !append(self, a) || !append_char(self, ':') || !append(self, b) || !append_char(self, '>')) return 0;
    return 1;
}

int fn_80366B18(Buffer *self, const char *a, const char *b, int unused, int arg4, int arg5)
{
    char text[16];
    int args[2];
    int *dt;
    args[0] = arg4;
    args[1] = arg5;
    dt = fn_8035D7B0(args);
    sprintf(text, lbl_8048E9E8, dt[5] + 0x76C, dt[4] + 1, dt[3], dt[2], dt[1], dt[0]);
    if (!open_tag(self, a, b) || !append(self, text) || !close_tag(self, a, b)) return 0;
    return 1;
}