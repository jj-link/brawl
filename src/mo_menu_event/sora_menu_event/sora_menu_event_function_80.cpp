#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
void __construct_array(void* base, void (*ctor)(void*), void (*dtor)(void*), unsigned long size, int count);
void* memset(void* p, int c, unsigned long n);
void fn_9_288(void*);
void fn_9_2BC(void*);
extern char lbl_9_data_0[];
extern char lbl_9_data_1C0[];
}

#define ZW(p, o) (*(int*)((char*)(p) + (o)) = 0)
#define ZBLK(p)                                                                                  \
    ZW(p, 0x44); ZW(p, 0x48); ZW(p, 0x4c); ZW(p, 0x50); ZW(p, 0x54); ZW(p, 0x58); \
    ZW(p, 0x5c); ZW(p, 0x60); ZW(p, 0x64); ZW(p, 0x68); ZW(p, 0x6c); ZW(p, 0x70); ZW(p, 0x74); \
    ZW(p, 0x78); ZW(p, 0x7c); ZW(p, 0x80); ZW(p, 0x84); ZW(p, 0x88); ZW(p, 0x8c); ZW(p, 0x90); \
    ZW(p, 0x94); ZW(p, 0x98); ZW(p, 0x9c); ZW(p, 0xa0); ZW(p, 0xa4); ZW(p, 0xa8); ZW(p, 0xac); \
    ZW(p, 0xb0); ZW(p, 0xb4); ZW(p, 0xb8); ZW(p, 0xbc); ZW(p, 0xc0); ZW(p, 0xc4); ZW(p, 0xc8); \
    ZW(p, 0xcc); ZW(p, 0xd0); ZW(p, 0xd4); ZW(p, 0xd8); ZW(p, 0xdc);

extern "C" void* fn_9_80(void* self, void* arg) {
    char* r4;
    int r5;
    unsigned char b;
    int i;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_9_data_0, 8, 15, 8, true);
    *(void**)((char*)self + 0x3c) = (void*)lbl_9_data_1C0;
    *(int*)((char*)self + 0x1a0) = 0;
    *(int*)((char*)self + 0x1a4) = 5;
    *(int*)((char*)self + 0x1a8) = 0;
    *(int*)((char*)self + 0x1ac) = 0;
    *(int*)((char*)self + 0x1b0) = 0;
    *(int*)((char*)self + 0x1b4) = 0;
    __construct_array((char*)self + 0x1b8, fn_9_288, fn_9_2BC, 0xa8, 3);

    b = *(unsigned char*)((char*)self + 0x2c);
    *(int*)((char*)self + 0x17b8) = 0;
    *(int*)((char*)self + 0x17bc) = 0;
    *(int*)((char*)self + 0x17c4) = 0;
    *(unsigned char*)((char*)self + 0x17e8) = 0;
    *(unsigned char*)((char*)self + 0x17e9) = 0;
    *(int*)((char*)self + 0x17ec) = 0;
    *(void**)((char*)self + 0x17f0) = arg;
    *(unsigned char*)((char*)self + 0x2c) = (unsigned char)(b & ~2);

    r5 = 0;
    r4 = (char*)self;
    for (i = 0; i < 2; i++) {
        ZW(r4, 0x40);
        r5 += 0x28;
        ZBLK(r4);
        r4 += 0xa0;
    }

    {
        char* r6 = (char*)self + r5 * 4;
        ZW(r6, 0x40); ZW(r6, 0x44); ZW(r6, 0x48); ZW(r6, 0x4c); ZW(r6, 0x50); ZW(r6, 0x54);
    }
    *(int*)((char*)self + 0x198) = 0;
    *(int*)((char*)self + 0x19c) = 0;
    *(int*)((char*)self + 0x1ac) = 0;
    *(int*)((char*)self + 0x1b0) = 0;
    *(int*)((char*)self + 0x1b4) = 0;
    memset((char*)self + 0x3b0, 0, 0xc00);
    memset((char*)self + 0xfb0, 0, 0x808);

    *(int*)((char*)self + 0x17cc) = 0;
    *(int*)((char*)self + 0x17d0) = 0;
    *(int*)((char*)self + 0x17d8) = 0;
    *(int*)((char*)self + 0x17dc) = 0;
    *(int*)((char*)self + 0x17e0) = -1;
    *(int*)((char*)self + 0x17e4) = -1;
    *(unsigned char*)((char*)self + 0x17d4) = 0;
    *(unsigned char*)((char*)self + 0x17d5) = 0;
    return self;
}
