#pragma force_active on
extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, int);
int fn_8001B7F8(const char*);
}
struct S {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct B { unsigned char pad[0x15]; unsigned char x : 8; };
extern "C" int fn_8001D134(S*);
extern "C" int fn_8001D740(S*);
extern "C" int fn_8001D5A8(S*);

extern "C" void fn_8001CE40(S* self) {
    char buf[128];
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
    S l;
    ((int*)&l)[0] = ((int*)self)[0];
    ((int*)&l)[1] = ((int*)self)[1];
    ((int*)&l)[2] = ((int*)self)[2];
    ((int*)&l)[3] = ((int*)self)[3];
    ((int*)&l)[4] = ((int*)self)[4];
    ((int*)&l)[5] = ((int*)self)[5];
    l.p = buf;
    int r = 3;
    switch (t) {
    case 0: r = 1; break;
    case 1: r = 3; break;
    case 2: r = fn_8001D134(&l); break;
    case 3: r = fn_8001D740(&l); break;
    case 4:
        ((B*)&l)->x = ((const unsigned char*)self->p)[2] - '0';
        r = fn_8001D5A8(&l);
        break;
    }
    self->r = r;
    if (r == 0) self->b = l.b;
}
