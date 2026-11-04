#include <types.h>
#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Voice {
    u8 pad00[0x18];
    s32 index;
    u32 flags;
    u8 pad20[0x14];
    u32 active;
    u8 pad38[4];
    u16 output[24];
    u8 pad6C[0x26];
    u16 volume;
    u16 volumeRamp;
    u8 pad96[0x6A];
    u16 state;
    u8 data[0x20];
} Voice;

typedef struct Entry {
    Voice *voice;
    u32 flags;
    s32 volume;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 base;
    s32 left;
    s32 right;
    s32 front;
    s32 rear;
    s32 surroundLeft;
    s32 surroundRight;
    u16 out3c;
    u16 pad3e;
    u16 out40;
    u16 pad42;
    u16 out44;
    u16 pad46;
    u16 out48;
    u16 pad4a;
    u16 out4c;
    u16 pad4e;
    u16 out50;
    u16 pad52;
    u16 out54;
    u16 pad56;
    u16 out58;
    u16 pad5a;
    u16 out5c;
    u16 pad5e;
    u16 out60;
    u16 pad62;
    u16 out64;
    u16 pad66;
    u16 out68;
    u16 pad6a;
    u16 out6c;
    u16 pad6e;
} Entry;

extern Entry *lbl_805A0B60;
extern s32 lbl_805A0B6C;
extern u16 lbl_8047B2E0[];

extern void fn_80206308(Entry *);
extern void fn_802097C4(s32);

static inline s32 convert(s32 value)
{
    s32 offset;
    if (value <= -0x388)
        return 0;
    if (value >= 0x3c)
        return 0xff64;
    offset = value + 0x388;
    return lbl_8047B2E0[offset];
}

#define CONVERT(dst, expression) ((dst) = convert(expression))

#define MODE0_CHANNEL(field, bit, x, y, z)                         \
    do {                                                            \
        if (entry->flags & (bit)) {                                 \
            CONVERT(entry->x, entry->field + entry->front);         \
            CONVERT(entry->y, entry->field + entry->front);         \
            CONVERT(entry->z, entry->field + entry->rear - 30);     \
        } else {                                                    \
            CONVERT(entry->x, entry->base + entry->field + entry->front); \
            CONVERT(entry->y, entry->base + entry->field + entry->front); \
            CONVERT(entry->z, entry->base + entry->field + entry->rear - 30); \
        }                                                           \
    } while (0)

#define MODE12_CHANNEL(field, bit, x, y, z)                         \
    do {                                                            \
        if (entry->flags & (bit)) {                                 \
            CONVERT(entry->x, entry->field + entry->left + entry->front); \
            CONVERT(entry->y, entry->field + entry->right + entry->front); \
            CONVERT(entry->z, entry->field + entry->rear - 30);     \
        } else {                                                    \
            CONVERT(entry->x, (entry->front + entry->left) + (entry->base + entry->field)); \
            CONVERT(entry->y, (entry->front + entry->right) + (entry->base + entry->field)); \
            CONVERT(entry->z, entry->base + entry->field + entry->rear - 30); \
        }                                                           \
    } while (0)

#define MODE3_CHANNEL(field, bit, x, y, z, w)                       \
    do {                                                            \
        if (entry->flags & (bit)) {                                 \
            CONVERT(entry->x, entry->field + entry->left + entry->front); \
            CONVERT(entry->y, entry->field + entry->right + entry->front); \
            CONVERT(entry->z, entry->field + entry->surroundLeft + entry->rear); \
            CONVERT(entry->w, entry->field + entry->surroundRight + entry->rear); \
        } else {                                                    \
            CONVERT(entry->x, (entry->front + entry->left) + (entry->base + entry->field)); \
            CONVERT(entry->y, (entry->front + entry->right) + (entry->base + entry->field)); \
            CONVERT(entry->z, (entry->rear + entry->surroundLeft) + (entry->base + entry->field)); \
            CONVERT(entry->w, (entry->rear + entry->surroundRight) + (entry->base + entry->field)); \
        }                                                           \
    } while (0)

#define COPY_OUTPUT(index, field, mask) \
    do {                                \
        *outputs++ = entry->field;      \
        if (outputs[-1] != 0)           \
            volume |= (mask);           \
        *outputs++ = 0;                 \
    } while (0)

void fn_80206500(Voice *voice, u32 flags, s32 volume, s32 a, s32 b,
                 s32 c, s32 d, s32 e, s32 base)
{
    u32 level;
    Entry *entry = &lbl_805A0B60[voice->index];
    u16 *outputs;

    entry->voice = voice;
    entry->flags = flags & 15;
    entry->volume = volume;
    entry->a = a;
    entry->b = b;
    entry->c = c;
    entry->d = d;
    entry->e = e;
    entry->base = base;
    fn_80206308(entry);

    if (entry->flags & 8)
        entry->out3c = 0;
    else
        CONVERT(entry->out3c, volume);

    volume = 0;
    switch (lbl_805A0B6C) {
    case 0:
        CONVERT(entry->out40, entry->base + entry->front);
        CONVERT(entry->out44, entry->base + entry->front);
        CONVERT(entry->out48, entry->base + entry->rear - 30);
        MODE0_CHANNEL(a, 1, out4c, out50, out54);
        MODE0_CHANNEL(b, 2, out58, out5c, out60);
        MODE0_CHANNEL(c, 4, out64, out68, out6c);
        break;

    case 1:
    case 2:
        CONVERT(entry->out40, entry->base + entry->left + entry->front);
        CONVERT(entry->out44, entry->base + entry->right + entry->front);
        CONVERT(entry->out48, entry->base + entry->rear - 30);
        MODE12_CHANNEL(a, 1, out4c, out50, out54);
        MODE12_CHANNEL(b, 2, out58, out5c, out60);
        MODE12_CHANNEL(c, 4, out64, out68, out6c);
        break;

    case 3:
        CONVERT(entry->out40, entry->base + entry->left + entry->front);
        CONVERT(entry->out44, entry->base + entry->right + entry->front);
        CONVERT(entry->out48, entry->base + entry->surroundLeft + entry->rear);
        CONVERT(entry->out64, entry->base + entry->surroundRight + entry->rear);
        MODE3_CHANNEL(a, 1, out4c, out50, out54, out68);
        MODE3_CHANNEL(b, 2, out58, out5c, out60, out6c);
        volume |= 0x80000000;
        break;
    }

    fn_802097C4(voice->index);
    level = OSDisableInterrupts();

    voice->volume = entry->out3c;
    voice->volumeRamp = 0;
    outputs = voice->output;
    COPY_OUTPUT(0, out40, 0x00000001);
    COPY_OUTPUT(2, out44, 0x00000002);
    COPY_OUTPUT(4, out4c, 0x00010000);
    COPY_OUTPUT(6, out50, 0x00020000);
    COPY_OUTPUT(8, out58, 0x00200000);
    COPY_OUTPUT(10, out5c, 0x00400000);
    COPY_OUTPUT(12, out64, 0x04000000);
    COPY_OUTPUT(14, out68, 0x08000000);
    COPY_OUTPUT(16, out48, 0x00000008);
    COPY_OUTPUT(18, out54, 0x00080000);
    COPY_OUTPUT(20, out60, 0x01000000);
    COPY_OUTPUT(22, out6c, 0x20000000);

    voice->active = volume;
    voice->flags |= 0x112;
    memset(voice->data, 0, 0x20);
    voice->state = 0;
    voice->flags |= 0x03000000;
    OSRestoreInterrupts(level);
}
