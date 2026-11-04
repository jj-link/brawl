#pragma force_active on

extern "C" {

typedef struct Entry {
    char name[0x20];
    int f20;
    int f24;
    int f28;
    int f2C;
} Entry;

typedef struct Manager {
    unsigned short unk0;
    unsigned short unk2;
    Entry *unk4;
    Entry *unk8;
} Manager;

unsigned char *fn_8016E4E8(void);
void *fn_8016E950(void *, void *);
void *fn_8016EB38(void *, void *);
void fn_8016EDA8(void *, void *, void *, void *, void *);
int strncmp(const char *, const char *, unsigned long);
char *strncpy(char *, const char *, unsigned long);

void fn_8001ACC4(Manager *mgr, const char *name, int a2, int a3, int a4) {
    int count;
    Entry *p1;
    Entry *p2;
    int i;
    p1 = mgr->unk4;
    p2 = p1;
    if (a2 != 0) {
        count = mgr->unk0;
        i = 0;
        while (i < count) {
            if (p2->f20 != 0 && strncmp(name, p2->name, 0x1f) == 0) {
                return;
            }
            i++;
            p2++;
        }
        for (; count > 0; count--) {
            if (p1->f20 == 0) {
                break;
            }
            p1++;
        }
        strncpy(p1->name, name, 0x1f);
        p1->f20 = a2;
        p1->f24 = a3;
        mgr->unk2 = mgr->unk2 + 1;
        if (a4 != 0) {
            mgr->unk8 = p1;
        }
        unsigned char *base = fn_8016E4E8();
        if (p1->f20 != 0) {
            p1->f28 = (int)fn_8016E950(base, (void *)p1->f20);
        }
        if (p1->f24 != 0) {
            p1->f2C = (int)fn_8016EB38(base, (void *)p1->f24);
        }
        if (a4 != 0) {
            fn_8016EDA8(base, 0, 0, (void *)mgr->unk8->f28,
                        (void *)mgr->unk8->f2C);
        } else {
            fn_8016EDA8(base, (void *)p1->f28, (void *)p1->f2C, 0,
                        (void *)mgr->unk8->f2C);
        }
    }
}

}
