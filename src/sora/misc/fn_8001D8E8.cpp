#pragma force_active on
extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, unsigned int);
int fn_8001B7F8(const char*);
int fn_8001DA24(char**);
int fn_8001DC28(char**);
int fn_8001DB34(char**);
}
struct A { const char* p; int a, b, c, d; unsigned r : 8; unsigned x : 8; unsigned y : 16; };
struct B { unsigned char pad[0x15]; unsigned char x : 8; };
extern "C" int fn_8001D8E8(A* self) {
    char buf[128];
    int t = fn_8001B7F8(self->p);
    const char* s = self->p;
    unsigned int n = strlen(s);
    const char* q = s;
    for (unsigned int i = 0; i < n; i++) {
        if (*q == ':') { strncpy(buf, q + 1, 128); goto done; }
        q++;
    }
    strncpy(buf, s, 128);
done:
    A l;
    ((int*)&l)[0] = ((int*)self)[0];
    ((int*)&l)[1] = ((int*)self)[1];
    ((int*)&l)[2] = ((int*)self)[2];
    ((int*)&l)[3] = ((int*)self)[3];
    ((int*)&l)[4] = ((int*)self)[4];
    ((int*)&l)[5] = ((int*)self)[5];
    l.p = buf;
    int r = 5;
    switch (t) {
    case 0: r = 5; break;
    case 2: r = fn_8001DA24((char**)&l); break;
    case 3: r = fn_8001DC28((char**)&l); break;
    case 4:
        ((B*)&l)->x = ((const unsigned char*)self->p)[2] - '0';
        r = fn_8001DB34((char**)&l);
        break;
    }
    return r;
}