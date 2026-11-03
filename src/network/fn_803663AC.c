#pragma force_active on
typedef struct Buffer { char *data; int length; int capacity; int changed; } Buffer;
extern char *fn_8035DFF8(char *, int);
extern void fn_8035DCB0(void *, int, int, int);
extern int fn_8035DCC0(void *, void *);
extern unsigned long strlen(const char *);
extern char *strcpy(char *, const char *);

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
int fn_803663AC(Buffer *self, const char *a, const char *b, int c, int d)
{
    int iter[3];
    char text[5];
    if (!open_tag(self, a, b))
        return 0;
    fn_8035DCB0(iter, c, d, 0);
    while (fn_8035DCC0(iter, text)) {
        text[4] = 0;
        if (!append(self, text)) return 0;
    }
    if (!close_tag(self, a, b))
        return 0;
    return 1;
}