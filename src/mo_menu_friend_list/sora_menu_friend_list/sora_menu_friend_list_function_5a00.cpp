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
void fn_800BF830(void* task);
void fn_800CC74C(void* task, u32 idx);
void fn_800CC8BC(void* task, u32 idx);
void exit__6gfTaskFv(void* task);
void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);
void printf__5MuMsgFUlPCce(void* msg, u32 index, const char* fmt, ...);
int sprintf(char* s, const char* fmt, ...);
char* strcpy(char* d, const char* s);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void* mdl, const char* name);
}

struct Info {
    u8 a, b, c;
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
};

extern "C" s32 fn_14_5A00(char* self) {
    u8 action;
    Info third;
    Info second;
    Info v2;
    Info first;
    Info v1;
    Info tv;
    char texture[32];
    char name[24];
    char result[40];
    char* data = lbl_14_data_0;

    s32 sum = *(s32*)(self + 0x24e4) + *(s32*)(self + 0x24d8);
    u8 idx = ((u8*)self)[sum + 0x22b8];
    s32 off = idx << 7;
    char* rec = self + off;
    u8 t = *(u8*)(rec + 0x2b9);
    if (t != 0xff) {
        u8 v;
        if (t < 0x80) {
            v = *(u8*)(self + t + 0x2a39);
        } else {
            v = 0;
        }
        sprintf(texture, data + 0x80, v);
        void* model = *(void**)(self + 0xa8);
        fn_800B7224(model, ((u32*)GetResMat__Q34nw4r3g3d6ResMdlCFPCc((char*)model + 8, data + 0x60))[3], texture, 0);
    } else {
        void* a = *(void**)(self + 0x2a2c);
        const char* nm = data + 0x60;
        u8 b = *(u8*)(rec + 0x2b8);
        void* model = *(void**)(self + 0xa8);
        s32 r3v;
        if (a == 0) {
            r3v = 0;
        } else {
            r3v = fn_80034924(a, b, result);
        }
        if (r3v != 0) {
            fn_800B70D0(model, nm, result);
        } else {
            const char* name2 = data + 0x6c;
            void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc((char*)model + 8, nm);
            fn_800B7224(model, ((u32*)mat)[3], name2, 0);
        }
    }

    strcpy(name, self + off + 0x2c1);
    printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), 0x14, name);

    u8 r27;
    u8 answer;
    s32 r28 = *(s32*)(self + off + 0x2bc);
    s32 r5 = r28 * 3;
    r27 = lbl_14_rodata_21C[r5];
    u8 r26 = lbl_14_rodata_21C[r5 + 1];
    u8 r25 = lbl_14_rodata_21C[r5 + 2];

    v1.a = r27;
    v1.b = r26;
    v1.c = r25;
    if (*(u8*)(self + 0x2a30) == 0 && (r28 == 6 || r28 == 0x12 || r28 == 0x16 || r28 == 0x1c)) {
        v1.a = 0x11;
        v1.c = 6;
    }
    *(u16*)&first = *(u16*)&v1;
    first.c = v1.c;
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x24cc), 0x15, first.a, 0);

    v2.a = r27;
    v2.b = r26;
    v2.c = r25;
    if (*(u8*)(self + 0x2a30) == 0 && (r28 == 6 || r28 == 0x12 || r28 == 0x16 || r28 == 0x1c)) {
        v2.a = 0x11;
        v2.c = 6;
    }
    *(u16*)&second = *(u16*)&v2;
    second.c = v2.c;
    if ((s32)second.b > 0) {
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), 0x16, data + 0x3fc, *(s32*)(self + off + 0x328), (s32)second.b);
    } else {
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), 0x16, data + 0x410);
    }

    s32 sum2 = *(s32*)(self + 0x24e4) + *(s32*)(self + 0x24d8);
    if (*(s32*)(self + 0x2a20) != *(s32*)(self + (((u8*)self)[sum2 + 0x22b8] << 7) + 0x2bc)) {
        fn_800BF830(*(void**)(self + 0x24ec));
        exit__6gfTaskFv(*(void**)(self + 0x24ec));
        *(void**)(self + 0x24ec) = 0;
        return 10;
    }

    char* task = *(char**)(self + 0x24ec);
    if (*(s32*)(task + 0x104) == 3) {
        answer = *(u8*)(task + 0x100);
        *(s32*)(self + 0x2abc) = *(s32*)(task + 0x124);
        exit__6gfTaskFv(task);
        *(void**)(self + 0x24ec) = 0;
        if (answer == 0) {
            MenuObject* obj = *(MenuObject**)(self + 0x2a1c);
            obj->v13(*(void**)(self + 0x1e0));
            return 7;
        }
        s32 st = *(s32*)(self + 0x2a20);
        s32 k = st * 3;
        tv.a = lbl_14_rodata_21C[k];
        tv.b = lbl_14_rodata_21C[k + 1];
        tv.c = lbl_14_rodata_21C[k + 2];
        if (*(u8*)(self + 0x2a30) == 0 && (st == 6 || st == 0x12 || st == 0x16 || st == 0x1c)) {
            tv.a = 0x11;
            tv.c = 6;
        }
        action = tv.c;
        *(u16*)&third = *(u16*)&tv;
        third.c = action;
        if ((u8)(action + 0xfc) <= 1) {
            if (*(u8*)(self + 0x40) == 0) {
                void* wifi = g_muWifiInterfaceTask;
                s32 sum3 = *(s32*)(self + 0x24e4) + *(s32*)(self + 0x24d8);
                u32 index = *(u8*)(self + (((u8*)self)[sum3 + 0x22b8] << 7) + 0x2b8);
                if (action == 4) {
                    fn_800CC74C(wifi, index);
                } else {
                    fn_800CC8BC(wifi, index);
                }
            }
            s32 next = 6;
            if (action == 4) {
                next = 5;
            }
            *(s32*)(self + 0x44) = next;
            return 0x21;
        }
        return 0xb;
    }
    return *(s32*)(self + 0x24c4);
}
