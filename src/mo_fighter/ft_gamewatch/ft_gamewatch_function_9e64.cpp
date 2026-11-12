#pragma force_active on
#include <types.h>

struct FtGwPair {
    int first;
    int second;
};

struct FtGwBlock {
    FtGwPair a;
    FtGwPair b;
    FtGwPair* p;
    void* v;
};

struct FtGwFlags {
    unsigned char a;
    unsigned char b;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern char lbl_107_data_AE8[];
extern char lbl_107_data_35E4[];
extern char lbl_107_data_3698[];
extern char lbl_107_data_372C[];
extern char lbl_107_data_32A0[];
extern char lbl_107_data_3410[];
extern char lbl_107_data_34A0[];
extern char lbl_107_data_2E98[];
extern char lbl_107_data_306C[];
extern char lbl_107_data_30F8[];
extern char lbl_107_data_29BC[];
extern char lbl_107_data_2BF8[];
extern char lbl_107_data_2C84[];
extern char lbl_107_data_240C[];
extern char lbl_107_data_26B0[];
extern char lbl_107_data_2740[];
extern char lbl_107_data_1D90[];
extern char lbl_107_data_209C[];
extern char lbl_107_data_2128[];
extern char lbl_107_data_13FC[];
extern char lbl_107_data_1774[];
extern char lbl_107_data_1804[];
extern char lbl_107_data_1894[];
extern char lbl_107_data_1924[];
extern char lbl_107_data_19B4[];
extern char lbl_107_data_10A0[];

void fn_27_1A558C(void* self, int v);
void fn_27_19F434(void* self, int a, int b);
void* fn_27_149950(void* acc, int idx, unsigned char* out);
void* fn_27_149928(void* acc, int idx, unsigned char* out);
void* fn_27_149914(void* acc, int idx, unsigned char* out);
void* fn_27_149900(void* acc, int idx, unsigned char* out);
void* fn_27_1498EC(void* acc, int idx, unsigned char* out);
void* fn_27_1498D8(void* acc, int idx, unsigned char* out);
void fn_107_1FC84(void* self, int idx, void* desc, void* val);
void fn_107_1CD90(void* self, int idx, void* desc, void* val);
void fn_107_1AF80(void* self, int idx, void* desc, void* val);
void fn_107_18C7C(void* self, int idx, void* desc, void* val);
void fn_107_16BB4(void* self, int idx, void* desc, void* val);
void fn_107_145EC(void* self, int idx, void* desc, void* val);
void fn_107_A26C(void* self, void* owner);
void fn_27_92F10(void* a, void* b, void* c, void* d, void* e);
}

extern "C" void* fn_107_9E64(u32 v, int kind) {
    FtGwFlags fl[6];
    FtGwBlock bl[6];
    char* r28;
    char* r27;
    char* owner;
    char* s;
    char* sub;
    char* r24;
    void* acc;
    char* r30;
    char* r31;
    char* q;
    char* x;
    char* y;

    s = (char*)v;
    owner = (char*)kind;

    fn_27_1A558C(s, 0);
    v = (u32)(s + 0x20);
    fn_27_19F434((char*)v, 5, 0);

    r28 = s + 0x7c;
    *(void**)r28 = (void*)lbl_107_data_AE8;
    *(void**)(r28 + 4) = (void*)(lbl_107_data_AE8 + 0x10);
    r27 = r28 + 8;
    *(void**)r27 = (void*)lbl_107_data_35E4;
    sub = r27 + 4;
    *(void**)sub = (void*)lbl_107_data_3698;
    r24 = sub + 8;
    *(void**)r24 = (void*)lbl_107_data_372C;

    fl[5].a = 0;
    fl[5].b = 0;
    bl[5].a.first = 0;
    bl[5].a.second = 18;
    kind = bl[5].a.second;
    v = *(u32*)(*(char**)(owner + 0xd8) + 0xc0);
    bl[5].b.first = 0;
    bl[5].b.second = bl[5].a.second;
    bl[5].p = &bl[5].b;
    bl[5].v = (void*)v;
    acc = fn_27_149950(g_ftCommonDataAccesser, kind, &fl[5].b);
    fn_107_1FC84(r24 + 4, 6, &bl[5].p, acc);
    *(void**)r27 = (void*)lbl_107_data_32A0;
    sub = r27 + 0x20f0;
    *(void**)sub = (void*)lbl_107_data_3410;
    r24 = sub + 8;
    *(void**)r24 = (void*)lbl_107_data_34A0;

    fl[4].a = 0;
    fl[4].b = 0;
    bl[4].a.first = 0;
    bl[4].a.second = 18;
    kind = bl[4].a.second;
    v = *(u32*)(*(char**)(owner + 0xd8) + 0xc0);
    bl[4].b.first = 0;
    bl[4].b.second = bl[4].a.second;
    bl[4].p = &bl[4].b;
    bl[4].v = (void*)v;
    acc = fn_27_149928(g_ftCommonDataAccesser, kind, &fl[4].b);
    fn_107_1CD90(r24 + 4, 5, &bl[4].p, acc);
    *(void**)r27 = (void*)lbl_107_data_2E98;
    sub = r27 + 0x4a18;
    *(void**)sub = (void*)lbl_107_data_306C;
    r24 = sub + 8;
    *(void**)r24 = (void*)lbl_107_data_30F8;

    fl[3].a = 0;
    fl[3].b = 0;
    bl[3].a.first = 0;
    bl[3].a.second = 18;
    kind = bl[3].a.second;
    v = *(u32*)(*(char**)(owner + 0xd8) + 0xc0);
    bl[3].b.first = 0;
    bl[3].b.second = bl[3].a.second;
    bl[3].p = &bl[3].b;
    bl[3].v = (void*)v;
    acc = fn_27_149914(g_ftCommonDataAccesser, kind, &fl[3].b);
    fn_107_1AF80(r24 + 4, 4, &bl[3].p, acc);
    *(void**)r27 = (void*)lbl_107_data_29BC;
    sub = r27 + 0x6b04;
    *(void**)sub = (void*)lbl_107_data_2BF8;
    r24 = sub + 8;
    *(void**)r24 = (void*)lbl_107_data_2C84;

    fl[2].a = 0;
    fl[2].b = 0;
    bl[2].a.first = 0;
    bl[2].a.second = 18;
    kind = bl[2].a.second;
    v = *(u32*)(*(char**)(owner + 0xd8) + 0xc0);
    bl[2].b.first = 0;
    bl[2].b.second = bl[2].a.second;
    bl[2].p = &bl[2].b;
    bl[2].v = (void*)v;
    acc = fn_27_149900(g_ftCommonDataAccesser, kind, &fl[2].b);
    fn_107_18C7C(r24 + 4, 3, &bl[2].p, acc);
    *(void**)r27 = (void*)lbl_107_data_240C;
    sub = r27 + 0x8c0c;
    *(void**)sub = (void*)lbl_107_data_26B0;
    r24 = sub + 8;
    *(void**)r24 = (void*)lbl_107_data_2740;

    fl[1].a = 0;
    fl[1].b = 0;
    bl[1].a.first = 0;
    bl[1].a.second = 18;
    kind = bl[1].a.second;
    v = *(u32*)(*(char**)(owner + 0xd8) + 0xc0);
    bl[1].b.first = 0;
    bl[1].b.second = bl[1].a.second;
    bl[1].p = &bl[1].b;
    bl[1].v = (void*)v;
    acc = fn_27_1498EC(g_ftCommonDataAccesser, kind, &fl[1].b);
    fn_107_16BB4(r24 + 4, 2, &bl[1].p, acc);
    *(void**)r27 = (void*)lbl_107_data_1D90;
    sub = r27 + 0xacf8;
    *(void**)sub = (void*)lbl_107_data_209C;
    r24 = sub + 8;
    *(void**)r24 = (void*)lbl_107_data_2128;

    fl[0].a = 0;
    fl[0].b = 0;
    bl[0].a.first = 0;
    bl[0].a.second = 18;
    kind = bl[0].a.second;
    v = *(u32*)(*(char**)(owner + 0xd8) + 0xc0);
    bl[0].b.first = 0;
    bl[0].b.second = bl[0].a.second;
    bl[0].p = &bl[0].b;
    bl[0].v = (void*)v;
    acc = fn_27_1498D8(g_ftCommonDataAccesser, kind, &fl[0].b);
    fn_107_145EC(r24 + 4, 1, &bl[0].p, acc);
    *(void**)r27 = (void*)lbl_107_data_13FC;
    sub = r27 + 0xcde0;
    r24 = sub + 4;
    *(void**)r24 = (void*)lbl_107_data_1774;
    q = r24 - 4;
    r31 = q + 8;
    *(void**)r31 = (void*)lbl_107_data_1804;
    x = r31 + 4;
    *(void**)x = (void*)lbl_107_data_1894;
    r30 = x + 4;
    *(void**)r30 = (void*)lbl_107_data_1924;
    y = r30 + 4;
    *(void**)y = (void*)lbl_107_data_19B4;
    fn_107_A26C(r30 + 0xc, owner);
    fn_107_A26C(r30 + 0x21b8, owner);
    fn_107_A26C(r31 + 0x436c, owner);
    fn_107_A26C(r31 + 0x6518, owner);
    fn_107_A26C(r24 + 0x86c8, owner);
    *(void**)r27 = (void*)lbl_107_data_10A0;
    *(unsigned char*)(r28 + 0x17660) = 0;
    fn_27_92F10(s + 0x176e0, owner, s, r28, s + 0x20);
    return s;
}
