#pragma force_active on
typedef struct Buffer {
    char *data;
    int length;
    int capacity;
    int changed;
} Buffer;

extern char lbl_8048E9C0[];
extern char *fn_8035DFF8(char *, int);
extern unsigned long strlen(const char *);
extern char *strcpy(char *, const char *);

static inline int reserve(Buffer *self, int capacity)
{
    char *data = fn_8035DFF8(self->data, capacity);
    if (data == 0)
        return 0;
    if (data != self->data)
        self->data = data;
    self->capacity = capacity;
    return 1;
}

static inline int append(Buffer *self, const char *str)
{
    unsigned long base = (unsigned long)str;
    const char *text = (const char *)base;
    int length = strlen(text);

    if (length == 0)
        return 1;

    while (self->capacity - self->length <= length) {
        if (!reserve(self, self->capacity + 0x400))
            return 0;
    }

    strcpy(self->data + self->length, text);
    self->length += length;
    return 1;
}

int fn_80362E4C(Buffer *self)
{
    if (!append(self, lbl_8048E9C0))
        return 0;
    self->changed = 1;
    return 1;
}
