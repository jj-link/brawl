#include <types.h>
#pragma force_active on

typedef union ValueData {
    s32 integer;
    f64 real;
    char *string;
} ValueData;

typedef struct Value {
    char *key;
    s32 type;
    s32 flag;
    ValueData data;
} Value;

extern void **lbl_805A10A8;
extern Value *fn_8035B1C4(void *, void *);
extern char *fn_8035D654(const char *);
extern void fn_8035E00C(void *);
extern void *fn_8035DFE8(s32);
extern s32 strlen(const char *);
extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);

void *fn_80383024(void **arg0, s32 arg1, char *arg2) {
    s32 key[5];
    Value *result;
    char *src;
    char *buf;
    char *copy;
    char *p;
    char c;

    if (arg0 == 0) {
        arg0 = lbl_805A10A8;
    }
    key[0] = arg1;
    result = fn_8035B1C4(*arg0, &key[0]);
    if (result == 0) {
        return 0;
    }
    if (result == 0) {
        src = 0;
    } else if (result->type == 2) {
        src = result->data.string;
    } else {
        src = (char *)&result->data;
    }
    buf = fn_8035DFE8(strlen(src) + strlen(arg2) + 1);
    strcpy(buf, src);
    strcat(buf, arg2);
    if (result->type == 0) {
        result->data.integer = *(s32 *)buf;
    } else if (result->type == 1) {
        result->data.real = *(f64 *)buf;
    } else if (result->type == 2) {
        if (result->data.string != 0) {
            fn_8035E00C(result->data.string);
        }
        if (buf == 0) {
            copy = 0;
        } else {
            p = fn_8035D654(buf);
            copy = p;
            while ((c = *p) != 0) {
                if (c == '\\') {
                    *p = '/';
                }
                p++;
            }
        }
        result->data.string = copy;
    }
    fn_8035E00C(buf);
    if (result == 0) {
        return 0;
    }
    if (result->type == 2) {
        return result->data.string;
    }
    return &result->data;
}
