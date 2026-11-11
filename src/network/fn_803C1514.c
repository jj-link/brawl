#pragma force_active on
extern int fn_803C2E94(int *);
extern char lbl_8053B248[];
typedef struct { unsigned int flag; int id; int value; } Rec;
static inline int find_id(int id) {
    unsigned int i; char *entry = lbl_8053B248 + 8;
    for (i = 1; i < 1; i++) {
        if ((*(int *)(entry + 0x40) &= 1) && id == *(int *)(entry + 0x44)) return 1;
        entry += 8;
    }
    return 0;
}
static inline void insert(int *id, int *out) {
    unsigned int i; char *entry = lbl_8053B248 + 0xc;
    for (i = 1; i < 1; i++) {
        if (!(*(int *)entry & 1)) {
            Rec *base = (Rec *)lbl_8053B248;
            base[i].flag |= 1;
            base[i].id = *id;
            *out = base[i].value;
            break;
        }
        entry += 0xc;
    }
}
int fn_803C1514(void) {
    int sp8; int id; unsigned int i; char *entry; int result = 0;
    fn_803C2E94(&sp8); id = sp8;
    for (i = 1, entry = lbl_8053B248 + 0xc; i < 1; i++) {
        if ((*(int *)entry & 1) && id == *(int *)(entry + 4)) {
            result = *(int *)(lbl_8053B248 + i * 0xc + 8); break;
        }
        entry += 0xc;
    }
    if (i == 1) {
        if (find_id(id)) insert(&sp8, &result);
        else result = *(int *)(lbl_8053B248 + 8);
    }
    return result;
}