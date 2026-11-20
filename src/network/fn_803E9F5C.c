#pragma force_active on
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern void fn_803EBBDC(int *);
extern char lbl_805644C0[];

typedef struct { unsigned int flag; int id; int value; } Rec;

static inline int find_id(int id) {
    unsigned int i;
    char *entry = lbl_805644C0 + 8;
    for (i = 1; i < 4; i++) {
        if ((*(unsigned int *)(entry + 0x80) &= 1) && id == *(int *)(entry + 0x84)) return 1;
        entry += 8;
    }
    return 0;
}

static inline void insert(int *id, int *out) {
    unsigned int i;
    char *entry = lbl_805644C0 + 0xc;
    for (i = 1; i < 4; i++) {
        if (!(*(int *)entry & 1)) {
            Rec *base = (Rec *)lbl_805644C0;
            base[i].flag |= 1;
            base[i].id = *id;
            *out = base[i].value;
            break;
        }
        entry += 0xc;
    }
}

int fn_803E9F5C(void) {
    int sp8;
    int id;
    int result;
    unsigned int i;
    unsigned int k;
    char *entry;
    char *p;
    int ok;

    PF_enterCritical(lbl_805644C0 + 0x64);
    result = 0;
    fn_803EBBDC(&sp8);
    id = sp8;
    entry = lbl_805644C0 + 0xC;
    for (i = 1; i < 4; i++) {
        if ((*(unsigned int *)entry & 1) && id == *(int *)(entry + 4)) {
            result = *(int *)(lbl_805644C0 + i * 0xC + 8);
            break;
        }
        entry += 0xC;
    }
    if (i == 4) {
        ok = find_id(id);
        if (ok) {
            insert(&sp8, &result);
        } else {
            result = *(int *)(lbl_805644C0 + 8);
        }
    }
    PF_exitCritical(lbl_805644C0 + 0x64);
    return result;
}
