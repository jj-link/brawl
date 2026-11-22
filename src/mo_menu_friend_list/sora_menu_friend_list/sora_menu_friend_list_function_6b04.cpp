#include <types.h>
#pragma force_active on
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
extern const char lbl_14_data_0[];
extern unsigned char lbl_14_rodata_21C[];
int sprintf(char*, const char*, ...);
char* strcpy(char*, const char*);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void fn_800B7224(void*, unsigned long, const char*, void*);
int fn_80034924(int, unsigned char, void*);
void fn_800B70D0(void*, const char*, void*);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
int fn_800BEEB8(int, int, int, int, int, int, int, int, int, int, int, int);
}

struct Col {
    unsigned char a, b, c;
};

inline int asInt(int value) { return value; }

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void call(void*, void*);
};

extern "C" void fn_14_6B04(char* self) {
    char* data = (char*)lbl_14_data_0;
    char name2[32];
    char name1[32];
    char buf[24];
    Col d2;
    Col s2;
    Col d1;
    Col s1;
    int off;
    int mode;

    if (*(int*)(self + 0x24C4) == 0xE) {
        int y;
        int x;
        x = *(int*)(self + 0x24E4);
        mode = 0x1B;
        y = *(int*)(self + 0x24D8);
        int selection = x + y;
        unsigned char sel = ((unsigned char*)self)[selection + 0x22B8];
        off = sel << 7;
        unsigned char t = *(unsigned char*)(self + off + 0x2B9);
        if (t != 0xFF) {
            unsigned char v;
            if (t < 0x80) {
                v = *(unsigned char*)(self + t + 0x2A39);
            } else {
                v = 0;
            }
            sprintf(name1, data + 0x80, v);
            char* model = *(char**)(self + 0xA8);
            void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(model + 8, data + 0x60);
            fn_800B7224(model, *(unsigned long*)((char*)mat + 0xC), name1, 0);
        } else {
            int ctx = *(int*)(self + 0x2A2C);
            const char* nm = data + 0x60;
            unsigned char b8 = *(unsigned char*)(self + off + 0x2B8);
            char* model = *(char**)(self + 0xA8);
            int res;
            if (ctx == 0) {
                res = 0;
            } else {
                res = fn_80034924(ctx, b8, name2);
            }
            if (res != 0) {
                fn_800B70D0(model, nm, name2);
            } else {
                const char* nm2 = data + 0x6C;
                void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(model + 8, nm);
                fn_800B7224(model, *(unsigned long*)((char*)mat + 0xC), nm2, 0);
            }
        }
        strcpy(buf, self + off + 0x2C1);
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), 0x14, buf);
        unsigned char ca;
        int idx = *(int*)(self + off + 0x2BC);
        int k = (idx << 2) - idx;
        ca = lbl_14_rodata_21C[k];
        unsigned char cb = *(&lbl_14_rodata_21C[k] + 1);
        unsigned char cc = *(&lbl_14_rodata_21C[k] + 2);
        s1.a = ca;
        s1.b = cb;
        s1.c = cc;
        if (*(unsigned char*)(self + 0x2A30) == 0 &&
            (idx == 6 || idx == 0x12 || idx == 0x16 || idx == 0x1C)) {
            s1.a = 0x11;
            s1.c = 6;
        }
        *(unsigned short*)&d1 = *(unsigned short*)&s1;
        d1.c = s1.c;
        printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x24CC), 0x15, d1.a,
                                  0);
        s2.a = ca;
        s2.b = cb;
        s2.c = cc;
        if (*(unsigned char*)(self + 0x2A30) == 0 &&
            (idx == 6 || idx == 0x12 || idx == 0x16 || idx == 0x1C)) {
            s2.a = 0x11;
            s2.c = 6;
        }
        *(unsigned short*)&d2 = *(unsigned short*)&s2;
        d2.c = s2.c;
        if (asInt(d2.b) > 0) {
            printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), 0x16, data + 0x3FC,
                                  *(int*)(self + off + 0x328), d2.b);
        } else {
            printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), 0x16, data + 0x410);
        }
        Obj* obj = *(Obj**)(self + 0x204);
        obj->call(*(void**)((char*)obj + 0xE4), *(void**)(self + 0x1E0));
    } else {
        mode = 0x1C;
    }
    *(int*)(self + 0x24EC) = fn_800BEEB8(1, *(int*)(*(int*)(self + 0x24CC) + 4), mode,
                                         *(int*)(self + 0x24F0), *(int*)(self + 0x2A1C), 0x1F, 0,
                                         0x2A, 0x2B, 0, 0, 0xF0);
}
