#pragma force_active on
typedef int s32;
typedef unsigned int u32;

typedef struct Buffer {
    char *data;
    s32 unk4;
    s32 length;
    s32 offset;
} Buffer;

extern s32 fn_8036A3E4(s32, s32, char *, s32, s32 *, s32 *, s32);
extern void *fn_803F602C(void *, const void *, u32);

s32 fn_8036A81C(s32 arg0, s32 arg1, Buffer *buffer, s32 *out,
                s32 compact, s32 arg5)
{
    s32 result;
    s32 consumed;
    s32 total;
    s32 remaining;
    char *data;
    s32 offset;
    s32 length;
    s32 error;

    length = buffer->length;
    offset = buffer->offset;
    data = buffer->data;
    remaining = length - offset;
    total = 0;

    if (remaining == 0) {
        return 0;
    }

    do {
        error = fn_8036A3E4(arg0, arg1, data + (offset + total),
                           remaining, &result, &consumed, arg5);
        if (error != 0) {
            return error;
        }
        if (consumed != 0) {
            total += consumed;
            remaining -= consumed;
        }
    } while (consumed != 0 && remaining != 0);

    if (compact != 0) {
        if (total > 0) {
            fn_803F602C(data, data + total, remaining + 1);
            length -= total;
        }
    } else {
        offset += total;
    }

    buffer->length = length;
    buffer->offset = offset;
    if (out != 0) {
        *out = result;
    }
    return 0;
}
