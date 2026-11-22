#include <types.h>
#pragma force_active on
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
extern char lbl_14_data_0[];
extern unsigned char lbl_14_rodata_21C[0x70];
extern void* g_muWifiInterfaceTask;
void fn_800B7224(void* model, u32 res, const char* name, void* tex);
void fn_800B70D0(void* model, const char* name, void* out);
s32 fn_80034924(void* p, u32 idx, void* out);
s32 fn_800CCF1C(void* task);
void exit__6gfTaskFv(void* task);
void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);
void printf__5MuMsgFUlPCce(void* msg, u32 index, const char* fmt, ...);
int sprintf(char* s, const char* fmt, ...);
char* strcpy(char* d, const char* s);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void* mdl, const char* name);
}

struct Entry {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    u16 d;
    u8 e;
    u8 pad2;
};

struct MenuObject {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13(void*) = 0;
    virtual void v14() = 0;
    virtual void v15(void*) = 0;
};

extern "C" s32 fn_14_6828(char* self) {
    char sp50[0x1c];
    char sp30[0x20];
    char sp18[0x18];
    Entry e2;
    Entry e1;
    char* data = lbl_14_data_0;

    s32 sum = *(s32*)(self + 0x24e4) + *(s32*)(self + 0x24d8);
    u8 idx = ((u8*)self)[sum + 0x22b8];
    s32 off = idx << 7;
    char* rec = self + idx * 128;
    u8 t = *(u8*)(rec + 0x2b9);
    if (t != 0xff) {
        u8 v;
        if (t < 0x80) {
            v = *(u8*)(self + t + 0x2a39);
        } else {
            v = 0;
        }
        sprintf(sp30, data + 0x80, v);
        void* model = *(void**)(self + 0xa8);
        fn_800B7224(model, ((u32*)GetResMat__Q34nw4r3g3d6ResMdlCFPCc((char*)model + 8, data + 0x60))[3], sp30, 0);
    } else {
        void* a = *(void**)(self + 0x2a2c);
        char* name = data + 0x60;
        u8 b = *(u8*)(rec + 0x2b8);
        void* model = *(void**)(self + 0xa8);
        s32 r3v;
        if (a == 0) {
            r3v = 0;
        } else {
            r3v = fn_80034924(a, b, sp50);
        }
        if (r3v != 0) {
            fn_800B70D0(model, name, sp50);
        } else {
            const char* name2 = data + 0x6c;
            void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc((char*)model + 8, name);
            fn_800B7224(model, ((u32*)mat)[3], name2, 0);
        }
    }

    strcpy(sp18, (char*)(self + off + 0x2c1));
    printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), 0x14, sp18);

    u8 r27;
    s32 r28 = *(s32*)(self + off + 0x2bc);
    s32 r5 = r28 * 3;
    r27 = lbl_14_rodata_21C[r5];
    u8 r26 = lbl_14_rodata_21C[r5 + 1];
    u8 r25 = lbl_14_rodata_21C[r5 + 2];

    e1.a = r27;
    e1.b = r26;
    e1.c = r25;
    if (*(u8*)(self + 0x2a30) == 0 && (r28 == 6 || r28 == 0x12 || r28 == 0x16 || r28 == 0x1c)) {
        e1.a = 0x11;
        e1.c = 6;
    }
    e1.d = *(u16*)&e1;
    e1.e = e1.c;
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x24cc), 0x15, *((u8*)&e1.d), 0);

    e2.a = r27;
    e2.b = r26;
    e2.c = r25;
    if (*(u8*)(self + 0x2a30) == 0 && (r28 == 6 || r28 == 0x12 || r28 == 0x16 || r28 == 0x1c)) {
        e2.a = 0x11;
        e2.c = 6;
    }
    e2.d = *(u16*)&e2;
    e2.e = e2.c;
    if ((s32)*((u8*)&e2.d + 1) > 0) {
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), 0x16, data + 0x3fc, *(s32*)(self + off + 0x328), *((u8*)&e2.d + 1));
    } else {
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), 0x16, data + 0x410);
    }

    if (*(u8*)(self + 0x40) == 0) {
        off = fn_800CCF1C(g_muWifiInterfaceTask);
    }
    if (off != 0 && *(s32*)(*(char**)(self + 0x24ec) + 0x104) == 3) {
        MenuObject* obj = *(MenuObject**)(self + 0x2a1c);
        obj->v13(*(void**)(self + 0x1e0));
        exit__6gfTaskFv(*(void**)(self + 0x24ec));
        *(void**)(self + 0x24ec) = 0;
        return 7;
    }
    return *(s32*)(self + 0x24c4);
}
