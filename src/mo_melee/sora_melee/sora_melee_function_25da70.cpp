#pragma force_active on
extern "C" {
extern unsigned int lbl_27_data_543A8[];
struct GG { int a; int a2; char* p; };
extern GG* g_GameGlobal;
extern void* g_ftManager;
int getEntryId__9ftManagerFi(void*, int);
int isValidEntryId__9ftManagerFi(void*, int);
unsigned char fn_27_10AA64(void*, int);
struct S { int z; int w; int y; int a; int d; int e; int f; };

int fn_27_25DA70(S* self) {
    unsigned int* t = lbl_27_data_543A8;
    int off, i;
    switch (self->e) {
    case 0:
        self->d = t[1];
        self->e = 0x2A;
    case 0x45:
    case 0x2A:
        i = 0;
        off = 0;
        for (; i < 4; i++, off += 0x5C) {
            if (*(unsigned char*)(g_GameGlobal->p + off + 0x99) == 0) {
                int id = getEntryId__9ftManagerFi(g_ftManager, i);
                if (isValidEntryId__9ftManagerFi(g_ftManager, id) != 0) {
                    if (fn_27_10AA64(g_ftManager, id) == 1) {
                        goto found;
                    }
                }
            }
        }
        self->d = t[2];
        self->e = 0x45;
        goto done;
    found:
        self->f = 0x3C;
    case 0x4E:
        while (self->f >= 0) {
            self->f = self->f - 1;
            self->d = t[3];
            self->e = 0x4E;
            goto done;
        }
        self->y = 7;
        self->a = 4;
        return 1;
    }
done:
    return 0;
}
}
