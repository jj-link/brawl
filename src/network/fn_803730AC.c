#include <string.h>
#pragma force_active on
extern void fn_8036AAF0(void *, int, int);
extern char lbl_8048FBA8[];
static inline int parse_error(void **ctx)
{
    char *obj = (char *)*ctx;
    strncpy(obj, lbl_8048FBA8, 0x100);
    obj[0xFF] = 0;
    *(int *)(obj + 0x434) = 1;
    fn_8036AAF0(ctx, 3, 1);
    return 3;
}
int fn_803730AC(void **ctx, char *input, int *offset, char *key, char *value)
{
    char *start;
    char *p;
    int count;
    int c;
    p = input + *offset;
    start = p++;
    if ((c = *start) != '\\')
        return parse_error(ctx);
    count = 0;
    while ((c = *p++) != '\\') {
        if (c == 0)
            return parse_error(ctx);
        if (count == 0x1FF)
            return parse_error(ctx);
        *key++ = c;
        count++;
    }
    *key = 0;
    count = 0;
    while ((c = *p++) != '\\' && c != 0) {
        if (count == 0x1FF)
            return parse_error(ctx);
        *value++ = c;
        count++;
    }
    *value = 0;
    *offset += p - start - 1;
    return 0;
}
