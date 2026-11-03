#include <types.h>
#pragma force_active on

typedef union ValueData {
    int integer;
    double real;
    char *string;
} ValueData;

typedef struct Value {
    char *key;
    int type;
    int flag;
    ValueData data;
} Value;

extern void **lbl_805A10A8;
extern char *fn_8035D654(const char *);
extern void fn_8035E00C(void *);
extern void fn_8035B078(void *, Value *);
extern Value *fn_8035B1C4(void *, Value *);

static inline void set_string(Value *v, const char *s) {
    char *copy;
    char *p;
    if (v->data.string != 0) {
        fn_8035E00C(v->data.string);
    }
    if (s == 0) {
        copy = 0;
    } else {
        p = fn_8035D654(s);
        copy = p;
        while (*p != 0) {
            if (*p == '\\') {
                *p = '/';
            }
            p++;
        }
    }
    v->data.string = copy;
}

void *fn_803822D8(void **obj, const char *key, int type, void *data) {
    Value v;
    Value query;
    Value *result;
    if (obj == 0) {
        obj = lbl_805A10A8;
    }
    v.key = fn_8035D654(key);
    v.type = type;
    v.data.string = 0;
    v.flag = 1;
    if (type == 0) {
        v.data.integer = *(int *)data;
    } else if (type == 1) {
        v.data.real = *(double *)data;
    } else if (type == 2) {
        set_string(&v, data);
    }
    fn_8035B078(*obj, &v);
    if (obj == 0) {
        obj = lbl_805A10A8;
    }
    query.key = (char *)key;
    result = fn_8035B1C4(*obj, &query);
    if (result == 0) {
        return 0;
    }
    if (result->type == 2) {
        return result->data.string;
    }
    return &result->data;
}
