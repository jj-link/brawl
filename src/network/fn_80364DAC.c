#pragma force_active on
#include <string.h>

typedef struct Buffer {
    char *data;
    int length;
    int capacity;
    int changed;
} Buffer;

extern char *fn_8035DFF8(char *, int);
extern int fn_80362510(unsigned int, unsigned char *);
extern int fn_80367280(Buffer *, const char *);

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
    if (!append_char(self, '<') || !append(self, a) ||
        !append_char(self, ':') || !append(self, b) ||
        !append_char(self, '>'))
        return 0;
    return 1;
}

static inline int close_tag(Buffer *self, const char *a, const char *b)
{
    if (!append_char(self, '<') || !append_char(self, '/') ||
        !append(self, a) || !append_char(self, ':') ||
        !append(self, b) || !append_char(self, '>'))
        return 0;
    return 1;
}

static inline int wlen(const unsigned short *s)
{
    const unsigned short *p = s;
    while (*p++ != 0) {
    }
    return p - s - 1;
}

static inline int append_wide(Buffer *self, const unsigned short *str)
{
    int strLen = 0;
    int pos = 0;
    int utf8Len = 0;
    char utf8String[4] = { '\0' };

    strLen = wlen(str);
    utf8String[3] = '\0';
    for (pos = 0; pos < strLen; pos++) {
        utf8Len = fn_80362510(str[pos], (unsigned char *)utf8String);
        utf8String[utf8Len] = '\0';
        if (!fn_80367280(self, utf8String))
            return 0;
    }
    return 1;
}

int fn_80364DAC(Buffer *self, const char *a, const char *b,
                const unsigned short *wide)
{
    const unsigned char *p;
    const unsigned short *scan;
    int i, length;

    p = (const unsigned char *)wide;
    do {
        p += 2;
    } while (*(const unsigned short *)(p - 2) != 0);
    length = (int)(p - (const unsigned char *)wide);
    length = ((int)((unsigned int)length >> 31) + length) >> 1;
    scan = wide;
    for (i = 0; i < length - 1; i++) {
        unsigned int ch = *scan;
        if (ch < 0x20) {
            if (ch != 9 && ch != 0xA && ch != 0xD)
                return 0;
        } else {
            if (ch > 0xD7FF && ch < 0xE000)
                return 0;
            if (ch > 0xFFFD)
                return 0;
        }
        scan++;
    }
    if (!open_tag(self, a, b) || !append_wide(self, wide) ||
        !close_tag(self, a, b))
        return 0;
    return 1;
}
