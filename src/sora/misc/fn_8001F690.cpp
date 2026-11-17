#pragma force_active on
extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, int);
int fn_8001B7F8(const char*);
int fn_8001F988(void*, int);
int fn_8001FC98(void*);
}

struct Arg {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct B { unsigned char pad[0x15]; unsigned char x : 8; };

extern "C" int fn_8001F690(Arg* self) {
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
    Arg l;
    ((int*)&l)[0] = ((int*)self)[0];
    ((int*)&l)[1] = ((int*)self)[1];
    ((int*)&l)[2] = ((int*)self)[2];
    ((int*)&l)[3] = ((int*)self)[3];
    ((int*)&l)[4] = ((int*)self)[4];
    ((int*)&l)[5] = ((int*)self)[5];
    l.p = buf;
    int r = 0x11;
    switch (t) {
    case 3: r = fn_8001FC98(&l); break;
    case 4: {
        int d = ((const unsigned char*)self->p)[2] - '0';
        ((B*)&l)->x = d;
        r = fn_8001F988(&l, d);
        break;
    }
    }
    self->c = l.c;
    self->b = l.b;
    self->r = r;
    return r;
}