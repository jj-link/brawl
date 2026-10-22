#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct Vec3f { float x, y, z; };

struct Payload { int w[12]; };

struct Callback {
    u32 field0;
    void* vtable;
    u32 field8;
    Payload data;
};

extern "C" {
extern void* fn_80158BE0();
extern u32 fn_8015911C(void* self, u32 bit, u32 kind);
extern s32 fn_40_4C48(s32 a, char* b, Vec3f* out);
extern void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void* mng, s32 kind, void* data);
extern void* __nw__FUlQ25Heaps8HeapType(u32 size, s32 type);
extern void fn_27_233F58(void* trigger, void* cb);
extern void fn_27_233FCC(void* trigger, void* cb);
extern void* g_stTriggerMng;
extern char lbl_40_data_890[];

s32 fn_40_49F8(s32 arg0, Payload* arg1) {
    Vec3f out;
    char* base = (char*)arg1;
    u16 val = *(u16*)(base + 0x2c);
    if (val == 0 || fn_8015911C(fn_80158BE0(), val, *(u8*)(base + 0x2f)) == 1) {
        fn_40_4C48(arg0, base, &out);
    } else {
        void* trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(
            g_stTriggerMng, 0, base + 0x2c);
        Callback* cb = (Callback*)__nw__FUlQ25Heaps8HeapType(0x3c, 0xf);
        if (cb) {
            cb->field0 = 0;
            cb->field8 = 0;
            cb->vtable = lbl_40_data_890;
            cb->data = *arg1;
        }
        fn_27_233F58(trigger, cb);
        u8 orig = *(u8*)(base + 1);
        if (orig != 0) {
            *(u8*)(base + 1) = 0;
        } else {
            *(u8*)(base + 1) = 1;
        }
        Callback* cb2 = (Callback*)__nw__FUlQ25Heaps8HeapType(0x3c, 0xf);
        if (cb2) {
            cb2->field0 = 0;
            cb2->field8 = 0;
            cb2->vtable = lbl_40_data_890;
            cb2->data = *arg1;
        }
        fn_27_233FCC(trigger, cb2);
        *(u8*)(base + 1) = orig;
    }
    return 0;
}
}
