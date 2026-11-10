#include <string.h>
#include <stdlib.h>
#pragma force_active on

extern char jumptable_8048F1C0[];
extern char lbl_804942B8[];
extern char lbl_8059F750[7];
extern char lbl_8059F758[8];
extern char lbl_8059F778[6];
extern char lbl_8059F788[6];
extern char lbl_8059F790[6];
extern char lbl_8059F798[6];
extern char lbl_8059F7A0[6];
extern char lbl_8059F7A8[6];
extern char lbl_8059F7B0[6];
extern char lbl_8059F7B8[5];
extern char lbl_8059F7C0[5];
extern char lbl_8059F7EC[4];
extern char lbl_8059F7F0[4];
extern char lbl_8059F7F4[4];

extern int fn_8036A328(void *, void *, const char *);
extern int fn_8036D2C8(void *, int, int);
extern void fn_80372DD8(char *, const char *, unsigned long);
extern void fn_803732E0(void *, const void *);
extern void fn_8037331C(unsigned char *, void *);
extern char *fn_8035D6C4(char *);

static inline int append_pair(char **ctx, char *state, int offset,
                              const char *name, const char *value)
{
    int result = fn_8036A328(ctx, state + offset, name);
    int next;
    int tmp;

    if (result != 0)
        return result;

    next = fn_8036A328(ctx, state + offset, value);
    tmp = 0;
    if (next != 0)
        tmp = next;
    return tmp;
}

static inline int invalid_char(int c)
{
    return c < 0 || c >= 0x100;
}

static inline int upper_char(int c)
{
    if (invalid_char(c))
        return c;
    return (*(unsigned char **)(*(char **)(lbl_804942B8 + 0x38) + 0x0c))[c];
}

#define APPEND_FIELD(offset, name, value)                           \
    do {                                                            \
        char *state = *ctx;                                         \
        int result = append_pair(ctx, state, (offset), (name), (value)); \
        if (result != 0)                                            \
            return result;                                          \
        goto success;                                               \
    } while (0)

#define COPY_FIELD(size, name)                         \
    do {                                               \
        fn_80372DD8(buffer, value, (size));            \
        APPEND_FIELD(0x45c, (name), buffer);           \
    } while (0)

#define INTEGER_FIELD(number)                          \
    do {                                               \
        int result = fn_8036D2C8(ctx, (number), atoi(value)); \
        if (result != 0)                               \
            return result;                             \
        goto success;                                  \
    } while (0)

int fn_8036DB08(char **ctx, int field, const char *value)
{
    char converted[0x30];
    char buffer[0x100];
    char *base = jumptable_8048F1C0;
    char *data = *ctx;
    int c;
    int invalid;

    if (value == 0) {
        fn_803732E0(ctx, base + 0x248);
        return 2;
    }

    switch (field) {
    case 0x700:
        if (*value == 0) {
            fn_803732E0(ctx, base + 0x248);
            return 2;
        }
        fn_80372DD8(buffer, value, 0x1f);
        fn_80372DD8(data + 0x110, buffer, 0x1f);
        {
            int result;
            base = *ctx;
            result = append_pair(ctx, base, 0x45c, lbl_8059F750, buffer);
            if (result != 0)
                return result;
            goto success;
        }

    case 0x701:
        if (*value == 0) {
            fn_803732E0(ctx, base + 0x248);
            return 2;
        }
        fn_80372DD8(buffer, value, 0x15);
        fn_80372DD8(data + 0x12f, buffer, 0x15);
        APPEND_FIELD(0x45c, base + 0x70, buffer);

    case 0x702:
        if (*value == 0) {
            fn_803732E0(ctx, base + 0x248);
            return 2;
        }
        fn_80372DD8(buffer, value, 0x33);
        fn_8035D6C4(buffer);
        fn_80372DD8(data + 0x144, buffer, 0x33);
        APPEND_FIELD(0x46c, lbl_8059F758, buffer);

    case 0x703:
        if (*value == 0) {
            fn_803732E0(ctx, base + 0x248);
            return 2;
        }
        fn_80372DD8(buffer, value, 0x1f);
        fn_80372DD8(data + 0x177, buffer, 0x1f);
        fn_8037331C((unsigned char *)(data + 0x177), converted);
        APPEND_FIELD(0x46c, base + 0x258, converted);

    case 0x704:
        COPY_FIELD(0x1f, base + 0x80);
    case 0x705:
        COPY_FIELD(0x1f, base + 0x8c);
    case 0x707:
        COPY_FIELD(0x4c, base + 0xa4);
    case 0x708:
        COPY_FIELD(0x0b, base + 0xb0);

    case 0x709:
        if (strlen(value) != 2) {
            fn_803732E0(ctx, base + 0x268);
            return 2;
        }
        COPY_FIELD(3, base + 0xbc);

    case 0x70b:
        c = upper_char((signed char)*value);
        if ((signed char)c == 'M')
            strcpy(buffer, lbl_8059F7EC);
        else if ((signed char)c == 'F')
            strcpy(buffer, lbl_8059F7F0);
        else
            strcpy(buffer, lbl_8059F7F4);
        APPEND_FIELD(0x45c, lbl_8059F778, buffer);

    case 0x706:
        COPY_FIELD(0x100, base + 0x98);
    case 0x70d:
        INTEGER_FIELD(0x70d);
    case 0x70e:
        INTEGER_FIELD(0x70e);
    case 0x70f:
        COPY_FIELD(0x100, base + 0x280);
    case 0x710:
        INTEGER_FIELD(0x710);
    case 0x711:
        COPY_FIELD(0x100, base + 0x294);
    case 0x712:
        INTEGER_FIELD(0x712);
    case 0x714:
        INTEGER_FIELD(0x714);
    case 0x715:
        INTEGER_FIELD(0x715);
    case 0x716:
        COPY_FIELD(0x100, base + 0x2a8);
    case 0x717:
        COPY_FIELD(0x33, lbl_8059F788);
    case 0x718:
        COPY_FIELD(0x100, lbl_8059F790);
    case 0x719:
        COPY_FIELD(0x100, lbl_8059F798);
    case 0x71a:
        COPY_FIELD(0x100, lbl_8059F7A0);
    case 0x71b:
        COPY_FIELD(0x100, lbl_8059F7A8);
    case 0x71c:
        COPY_FIELD(0x100, lbl_8059F7B0);
    case 0x71d:
        COPY_FIELD(0x100, lbl_8059F7B8);
    case 0x71e:
        COPY_FIELD(0x100, lbl_8059F7C0);

    default:
        fn_803732E0(ctx, base + 0x1d4);
        return 2;
    }

success:
    return 0;
}
