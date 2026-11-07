#pragma force_active on
typedef struct Entry { signed char *name; int type; void *data; int count; } Entry;
int fn_8038DDDC(Entry *p, int n) {
    int i;
    for (i = 0; i < n; i++, p++) {
        if (!p->name || !*p->name) return 7;
        if (p->type < 0 || p->type >= 9) return 8;
        if (p->type == 4 && !p->data) return 9;
        if (p->type == 5 && !p->data) return 9;
        if (p->type == 8) {
            if (p->count < 0) return 9;
            if (!p->data && p->count > 0) return 9;
        }
    }
    return 0;
}