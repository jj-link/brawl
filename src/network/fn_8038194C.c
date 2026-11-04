#include <string.h>
#include <stdio.h>
#pragma force_active on

extern const char lbl_8059FAE0[3];

typedef struct Context {
    char pad0[0x3c];
    int error;
    char pad40[0xe0];
    int done;
    char pad124[0x10];
    int flag;
    char buffer[12];
    int used;
    int remaining;
    int state;
} Context;

extern int fn_80381868(Context *, const char *, int);

int fn_8038194C(Context *self, const char *data, int size) {
    int parsed;
    int value;
    int chunk;

    if (self->flag != 0) {
        int zero = 0;
        while (size > 0) {
            if (self->state == 0) {
                char *end = strchr(data, '\n');
                if (end != 0) {
                    int n = end - data;
                    if (n != 0 && self->used < 10) {
                        if (10 - self->used < n)
                            n = 10 - self->used;
                        memcpy(self->buffer + self->used, data, n);
                        self->used += n;
                        self->buffer[self->used] = zero;
                    }
                    end++;
                    size -= end - data;
                    data = end;
                    if (sscanf(self->buffer, lbl_8059FAE0, &parsed) != 1)
                        value = -1;
                    else
                        value = parsed;
                    self->remaining = value;
                    if (value == -1) {
                        self->done = 1;
                        self->error = 7;
                        return 0;
                    }
                    if (value == 0)
                        self->state = 3;
                    else
                        self->state = 1;
                } else {
                    if (size != 0 && self->used < 10) {
                        if (10 - self->used < size)
                            size = 10 - self->used;
                        memcpy(self->buffer + self->used, data, size);
                        self->used += size;
                        self->buffer[self->used] = zero;
                    }
                    return 1;
                }
            } else if (self->state == 1) {
                chunk = self->remaining < size ? self->remaining : size;
                if (fn_80381868(self, data, chunk) == 0)
                    return 0;
                data += chunk;
                size -= chunk;
                self->remaining -= chunk;
                if (self->remaining == 0)
                    self->state = 2;
            } else if (self->state == 2) {
                char *end = strchr(data, '\n');
                if (end == 0)
                    return 1;
                end++;
                self->buffer[0] = zero;
                size -= end - data;
                self->used = zero;
                data = end;
                self->remaining = zero;
                self->state = zero;
            } else if (self->state == 3) {
                self->done = 1;
                return 1;
            } else {
                return 0;
            }
        }
        return 1;
    }
    return fn_80381868(self, data, size);
}
