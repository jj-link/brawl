#include <string.h>
#pragma force_active on

struct S {
    unsigned char pad[0x578];
    unsigned int offset;
};

int fn_8037933C(struct S* self, const char* str) {
    int len = strlen(str) + 1;
    int remaining = 0x578 - self->offset;
    unsigned int newoff;
    if (len > remaining) {
        len = remaining;
    }
    if (len <= 0) {
        return 0;
    }
    memcpy(self->pad + self->offset, str, len);
    newoff = self->offset + len;
    self->offset = newoff;
    self->pad[newoff - 1] = 0;
    return 1;
}
