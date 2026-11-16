#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
int fn_8001B7F8(const char*);
int fn_8001B8E0(int, int);
int fn_8001E510(void*, int);
int fn_8001E630(void*);
int fn_8020AD88(char*, int, int*);
void fn_8020D38C(char*);
char* strcat(char*, const char*);
unsigned int strlen(const char*);
int strncmp(const char*, const char*, unsigned int);
char* strncpy(char*, const char*, int);
extern char lbl_80421340[0x15];
extern char lbl_80494910[0x18];
extern char lbl_8059C57C[5];
}
struct S {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct B { unsigned char pad[0x15]; unsigned char x : 8; };
struct Guard {
    void* mutex;
    unsigned char flag : 8;
};

extern "C" int fn_8001E2F8(S* self) {
    int out;
    int r;
    Guard g;
    Guard* p = &g;
    S l;
    char buf[128];
    char s176[128];
    char s30[128];
    int t = fn_8001B7F8(self->p);
    const char* s = self->p;
    unsigned int n = strlen(s);
    const char* q = s;
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (*q == ':') {
            strncpy(buf, q + 1, 128);
            goto done;
        }
        q++;
    }
    strncpy(buf, s, 128);
done:
    r = 5;
    ((int*)&l)[0] = ((int*)self)[0];
    ((int*)&l)[1] = ((int*)self)[1];
    ((int*)&l)[2] = ((int*)self)[2];
    ((int*)&l)[3] = ((int*)self)[3];
    ((int*)&l)[4] = ((int*)self)[4];
    ((int*)&l)[5] = ((int*)self)[5];
    l.p = buf;
    switch (t) {
    case 2: {
        p->flag = 1;
        p->mutex = lbl_80494910;
        if (p->flag != 0) OSLockMutex(p->mutex);
        const char* name = l.p;
        s30[0] = 0;
        int result = 0x12;
        if (strncmp(name, lbl_8059C57C, 4) == 0) {
            strcat(s30, name);
        } else {
            fn_8020D38C(s176);
            strncpy(s30, s176, 0x40);
            strcat(s30, name);
        }
        int rv = fn_8020AD88(s30, 0, &out);
        if (rv != 0) {
            fn_8001B8E0(rv, 0);
            OSReport(lbl_80421340, s30);
        } else {
            result = 0;
        }
        if (p->flag != 0) OSUnlockMutex(p->mutex);
        r = result;
        break;
    }
    case 3:
        r = fn_8001E630(&l);
        break;
    case 4: {
        int d = ((const unsigned char*)self->p)[2] - '0';
        ((B*)&l)->x = d;
        r = fn_8001E510(&l, d);
        break;
    }
    }
    self->r = r;
    return r;
}
