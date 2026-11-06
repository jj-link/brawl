#pragma force_active on

typedef struct Buffer {
    char *data;
    int length;
    int capacity;
    int changed;
} Buffer;

extern char *fn_8035DFF8(char *, int);
extern int fn_80367280(Buffer *, const char *);
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

static inline int append_char(Buffer *self, char c)
{
    if (self->length >= self->capacity) {
        if (!reserve(self, self->capacity + 0x400))
            return 0;
    }
    self->data[self->length] = c;
    self->length++;
    return 1;
}

static inline int append(Buffer *self, const char *str)
{
    int length = strlen(str);
    if (length == 0)
        return 1;

    while (self->capacity - self->length <= length) {
        if (!reserve(self, self->capacity + 0x400))
            return 0;
    }

    strcpy(self->data + self->length, str);
    self->length += length;
    return 1;
}

static inline int open_tag(Buffer *self, const char *a, const char *b)
{
    int ok;
    if (append_char(self, '<') == 0 || append(self, a) == 0 || append_char(self, ':') == 0 || append(self, b) == 0 || append_char(self, '>') == 0)
        ok = 0;
    else
        ok = 1;
    if (ok == 0)
        return 0;
    return 1;
}

static inline int close_tag(Buffer *self, const char *a, const char *b)
{
    int ok;
    if (append_char(self, '<') == 0 || append_char(self, '/') == 0 || append(self, a) == 0 || append_char(self, ':') == 0 || append(self, b) == 0 || append_char(self, '>') == 0)
        ok = 0;
    else
        ok = 1;
    if (ok == 0)
        return 0;
    return 1;
}

int fn_803646CC(Buffer *self, const char *a, const char *b, const char *name)
{
    int len = strlen(name);
    const char *p = name;
    int i;

    for (i = len; i > 0; --i) {
        unsigned char c = *p;
        if (c < 0x20) {
            if (c != 9 && c != 0xA && c != 0xD)
                return 0;
        }
        p++;
    }

    if (open_tag(self, a, b) == 0 || fn_80367280(self, name) == 0 || close_tag(self, a, b) == 0)
        return 0;
    return 1;
}
