#pragma force_active on
#include <string.h>
#include <internal/printf.h>

typedef struct Buffer { char *data; int length; int capacity; int changed; } Buffer;
extern char *fn_8035DFF8(char *, int);
extern char lbl_8059F5B8, lbl_8059F5C0, lbl_8059F5C8;
extern char lbl_8059F5D0, lbl_8059F5D8, lbl_8059F5F8;
extern char lbl_8048EA08[];

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
int fn_80367280(Buffer *self, const char *str)
{
    const char *amp, *apos, *quot, *lt, *gt, *space;
    int len, i;
    char text[8];
    len = strlen(str);
    i = 0;
    amp = &lbl_8059F5B8; apos = &lbl_8059F5C8; quot = &lbl_8059F5C0;
    lt = &lbl_8059F5D0; gt = &lbl_8059F5D8; space = &lbl_8059F5F8;
    for (; i < len; i++, str++) {
        unsigned char raw = *str;
        char c = raw;
        int result;
        if (c == '&') result = append(self, amp);
        else if (c == '\'') result = append(self, apos);
        else if (c == '"') result = append(self, quot);
        else if (c == '<') result = append(self, lt);
        else if (c == '>') result = append(self, gt);
        else if (c == ' ') result = append(self, space);
        else if (c < 0x20 || raw > 0x7f) {
            sprintf(text, lbl_8048EA08, raw);
            text[6] = 0;
            result = append(self, text);
        } else result = append_char(self, c);
        if (!result) return 0;
    }
    return 1;
}