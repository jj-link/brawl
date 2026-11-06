#pragma force_active on
typedef struct Entry {
    int key;
    int type;
    int count;
    unsigned int pad;
    union {
        int i;
        double d;
        char *s;
    } value;
} Entry;

extern void **lbl_805A10A8;
extern int lbl_805A1098;
extern double lbl_805A10A0;

extern Entry *fn_8035B1C4(void *, int *);
extern char *fn_8035D654(const char *);
extern void fn_8035E00C(void *);

static inline void *get_value(Entry *e) {
    if (e == 0)
        return 0;
    if (e->type == 2)
        return e->value.s;
    return &e->value;
}

static inline void set_value(Entry *e, void *p) {
    char *s, *q;

    if (e->type == 0) {
        e->value.i = *(int *)p;
    } else if (e->type == 1) {
        e->value.d = *(double *)p;
    } else if (e->type == 2) {
        if (e->value.s != 0)
            fn_8035E00C(e->value.s);
        if (p == 0) {
            s = 0;
        } else {
            q = fn_8035D654((char *)p);
            s = q;
            while (*q != 0) {
                if (*q == 0x5c)
                    *q = 0x2f;
                q++;
            }
        }
        e->value.s = s;
    }
}

static inline int *average_int(Entry *e, void *value) {
    lbl_805A1098 =
        (*(int *)value + e->count * *(int *)get_value(e)) / ++e->count;
    return &lbl_805A1098;
}

static inline double *average_double(Entry *e, void *value) {
    lbl_805A10A0 =
        (*(double *)value + (double)e->count * *(double *)get_value(e)) /
        (double)++e->count;
    return &lbl_805A10A0;
}

void *fn_803831AC(void **obj, int key, void *value) {
    Entry *e;
    struct {
        int key;
        char padding[16];
    } local;

    if (obj == 0)
        obj = lbl_805A10A8;
    local.key = key;
    e = fn_8035B1C4(*obj, &local.key);
    if (e == 0)
        return 0;
    if (e->type == 0) {
        set_value(e, average_int(e, value));
        return get_value(e);
    }
    if (e->type == 1) {
        set_value(e, average_double(e, value));
        return get_value(e);
    }
    return get_value(e);
}
