#pragma force_active on
typedef struct Entry { signed char *name; int type; void *data; int count; } Entry;
extern int fn_8038DDDC(Entry *p, int n);
struct Inner {
    int first;
    Entry *third;
    int second;
};
struct S {
    char pad[8];
    struct Inner *p;
};
static int getSecond(struct Inner *p) {
    return p->second;
}
int fn_8038E1C0(struct S *arg) {
    struct Inner *p = arg->p;
    int second;
    Entry *third;
    if (p->first == 0) return 4;
    second = getSecond(p);
    if (second < 0) return 6;
    third = p->third;
    if (third == 0 && second > 0) return 5;
    return fn_8038DDDC(third, second);
}