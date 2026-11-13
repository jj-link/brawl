#pragma force_active on

extern "C" {
unsigned char* fn_8016E4E8(void);
int fn_8016F008(void* a, void* b);
int fn_8016F0A8(void* a, void* b);
void gfMemFill__FPvUcUl(void* p, unsigned char c, unsigned long n);
int strncmp(const char* a, const char* b, unsigned long n);
}

struct Entry {
    char name[0x20];
    void* p20;
    void* p24;
    void* p28;
    void* p2c;
};

struct Header {
    unsigned short count;
    unsigned short active;
    Entry* base;
    Entry* last;
};

extern "C" void fn_8001AE1C(Header* h, const char* name) {
    unsigned short n;
    Header* hp = h;
    Entry* e = hp->base;
    n = hp->count;
    int i = 0;
    while (i < (int)n) {
        if (e->p20 != 0 && strncmp(name, e->name, 0x1f) == 0) {
            break;
        }
        i++;
        e++;
    }
    if (i < (int)n) {
        unsigned char* base = fn_8016E4E8();
        if (e->p28 != 0) {
            fn_8016F008(base, e->p28);
        }
        if (e->p2c != 0) {
            fn_8016F0A8(base, e->p2c);
        }
        gfMemFill__FPvUcUl(e, 0, 0x20);
        e->p20 = 0;
        e->p24 = 0;
        e->p28 = 0;
        e->p2c = 0;
        if (hp->last == e) {
            hp->last = 0;
        }
        hp->active = hp->active - 1;
    }
}
