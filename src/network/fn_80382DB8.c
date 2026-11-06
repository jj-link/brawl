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
extern s32 lbl_805A1098;
extern f64 lbl_805A10A0;
extern Value *fn_8035B1C4(void *, void *);
extern char *fn_8035D654(const char *);
extern void fn_8035E00C(void *);

void *fn_80382DB8(void **arg0, s32 arg1, void *arg2) {
    s32 key[5];
    Value *result;
    void *source;
    void *global;
    f64 real_value;
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

    if (result->type == 0) {
        if (result == 0) {
            source = 0;
        } else if (result->type == 2) {
            source = result->data.string;
        } else {
            source = &result->data;
        }
        global = &lbl_805A1098;
        lbl_805A1098 = *(s32 *)source / *(s32 *)arg2;

        if (result->type == 0) {
            result->data.integer = lbl_805A1098;
        } else if (result->type == 1) {
            result->data.real = *(f64 *)global;
        } else if (result->type == 2) {
            if (result->data.string != 0) {
                fn_8035E00C(result->data.string);
            }
            if (global == 0) {
                copy = 0;
            } else {
                p = fn_8035D654((const char *)global);
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

        if (result == 0) {
            return 0;
        }
        if (result->type == 2) {
            return result->data.string;
        }
        return &result->data;
    } else if (result->type == 1) {
        if (result == 0) {
            source = 0;
        } else if (result->type == 2) {
            source = result->data.string;
        } else {
            source = &result->data;
        }
        real_value = *(f64 *)source / *(f64 *)arg2;
        global = &lbl_805A10A0;
        lbl_805A10A0 = real_value;

        if (result->type == 0) {
            result->data.integer = *(s32 *)global;
        } else if (result->type == 1) {
            result->data.real = real_value;
        } else if (result->type == 2) {
            if (result->data.string != 0) {
                fn_8035E00C(result->data.string);
            }
            if (global == 0) {
                copy = 0;
            } else {
                p = fn_8035D654((const char *)global);
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

        if (result == 0) {
            return 0;
        }
        if (result->type == 2) {
            return result->data.string;
        }
        return &result->data;
    }

    if (result == 0) {
        return 0;
    }
    if (result->type == 2) {
        return result->data.string;
    }
    return &result->data;
}
