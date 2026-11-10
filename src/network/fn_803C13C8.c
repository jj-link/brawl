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
static inline void insert(int arg0, int *id) {
    unsigned int i; char *entry = lbl_8053B248 + 0xC;
    for (i = 1; i < 1; i++) {
        if (!(*(int *)entry & 1)) {
            Rec *base = (Rec *)lbl_8053B248;
            base[i].flag |= 1;
            base[i].id = *id;
            base[i].value = arg0;
            break;
        }
        entry += 0xC;
    }
}
void fn_803C13C8(int arg0) {
    int sp8; int id; unsigned int i; char *entry;
    fn_803C2E94(&sp8); id = sp8;
    i = 1; entry = lbl_8053B248 + 0xC;
    while (i < 1) {
        if ((*(int *)entry & 1) && id == *(int *)(entry + 4)) {
            *(int *)(lbl_8053B248 + i * 0xC + 8) = arg0; break;
        }
        entry += 0xC; i++;
    }
    if (i == 1) {
        if (find_id(id)) insert(arg0, &sp8);
    }
    *(int *)(lbl_8053B248 + 8) = arg0;
}