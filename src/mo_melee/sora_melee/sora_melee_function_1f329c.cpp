#include <sr/sr_common.h>
#pragma force_active on

#define IP_FIELD(type, base, off) (*(type*)((char*)(base) + (off)))

extern "C" {
extern void* g_aiMgr;
extern char lbl_27_data_48598[];
extern const float lbl_27_rodata_2CF0;
void __ct__7IpHumanFUl(void* self, unsigned long contNo);
void fn_27_21CD58(void* a, void* b);
void fn_27_1F1958(void* mgr, int index, signed char state, void* self, int arg);
void fn_27_21DB30(void* a, signed char b, int c, int d);
void* fn_27_1F21B8(void);
int fn_27_1F2C78(void* p);
void fn_27_1F1C5C(void* mgr, int index, void* self, int arg);
int fn_27_1F1F58(void* p);
void* fn_27_20C59C(void* obj, void* self, int arg);
void fn_27_20DB40(void* obj, unsigned int a, signed char* b, unsigned int c, unsigned int d);
}

extern "C" void* fn_27_1F329C(void* arg0, unsigned long arg1, int arg2, int arg3, int arg4, int arg5, void* arg6, Heaps::HeapType arg7) {
    __ct__7IpHumanFUl(arg0, arg1);
    IP_FIELD(signed char, arg0, 0x41) = -1;
    IP_FIELD(void*, arg0, 0x4) = lbl_27_data_48598;
    IP_FIELD(signed char, arg0, 0x42) = -1;
    IP_FIELD(signed char, arg0, 0x43) = -1;
    fn_27_21CD58((char*)arg0 + 0x90, lbl_27_data_48598);
    IP_FIELD(signed char, arg0, 0x110) = -1;
    IP_FIELD(int, arg0, 0x2C) = arg2;
    int t7 = arg3 + (arg6 != 0) * 7;
    IP_FIELD(int, arg0, 0x30) = arg4;
    IP_FIELD(signed char, arg0, 0x42) = t7;
    IP_FIELD(signed char, arg0, 0x43) = 0;
    IP_FIELD(unsigned char, arg0, 0x112) = *(unsigned char*)((char*)g_aiMgr + 0xA1);
    IP_FIELD(signed char, arg0, 0x113) = 0;
    IP_FIELD(signed char, arg0, 0x114) = 1;
    IP_FIELD(short, arg0, 0x116) = 0x2FF;
    IP_FIELD(unsigned short, arg0, 0x3C) = 0x8000;
    IP_FIELD(signed char, arg0, 0x110) = t7;
    IP_FIELD(short, arg0, 0x58) = 0;
    IP_FIELD(short, arg0, 0x5A) = 0;
    IP_FIELD(short, arg0, 0x6A) = 0;
    IP_FIELD(int, arg0, 0x6C) = 1;
    IP_FIELD(signed char, arg0, 0x74) = 0;
    IP_FIELD(signed char, arg0, 0x60) = 0;
    IP_FIELD(signed char, arg0, 0x61) = 0;
    IP_FIELD(signed char, arg0, 0x62) = 0;
    IP_FIELD(signed char, arg0, 0x63) = 0;
    IP_FIELD(signed char, arg0, 0x64) = 0;
    IP_FIELD(signed char, arg0, 0x65) = 0;
    IP_FIELD(signed char, arg0, 0x66) = 0;
    IP_FIELD(short, arg0, 0x68) = 0;
    IP_FIELD(signed char, arg0, 0x67) = -1;
    IP_FIELD(signed char, arg0, 0x75) = 0;
    IP_FIELD(int, arg0, 0x34) = 0;
    IP_FIELD(int, arg0, 0x84) = 0;
    IP_FIELD(short, arg0, 0x88) = 0;
    if (arg6 == 0) {
        void* mgr = g_aiMgr;
        int var;
        if (arg3 < 0 || (unsigned int)arg3 >= 0xEU) {
            var = -1;
        } else {
            var = *(unsigned char*)((char*)mgr + arg3 + 0x84);
        }
        int st = (signed char)var;
        int state = (st == -1) ? arg5 : st;
        fn_27_1F1958(mgr, arg3, (signed char)state, arg0, arg4);
    } else {
        IP_FIELD(void*, arg6, 0x34) = arg0;
        fn_27_21DB30((void*)((unsigned int)arg0 + 0x90), *(signed char*)((char*)fn_27_1F21B8() + 0x1D), 0, 1);
        void* mgr = g_aiMgr;
        int idx = fn_27_1F2C78((char*)arg6 + 0x42);
        fn_27_1F1C5C(mgr, idx, arg0, arg4);
    }
    void* obj = operator new(0x114, arg7);
    void* var24 = obj;
    if (obj != 0) {
        var24 = fn_27_20C59C(var24, arg0, fn_27_1F1F58((void*)((unsigned int)arg0 + 0x42)));
    }
    IP_FIELD(void*, arg0, 0x44) = var24;
    signed char sp8 = -1;
    fn_27_20DB40(IP_FIELD(void*, arg0, 0x44), 0, &sp8, 0, 0);
    int var5 = 0x79;
    if (arg6 == 0) {
        var5 = 1;
    }
    IP_FIELD(int, arg0, 0x4C) = var5;
    IP_FIELD(int, arg0, 0x48) = var5;
    IP_FIELD(int, arg0, 0x50) = 0;
    IP_FIELD(int, arg0, 0x54) = 0;
    IP_FIELD(short, arg0, 0x5C) = 0;
    IP_FIELD(short, arg0, 0x5E) = 0;
    IP_FIELD(short, arg0, 0x8A) = 0;
    IP_FIELD(signed char, arg0, 0x111) = 0;
    IP_FIELD(int, arg0, 0x38) = 0;
    IP_FIELD(int, arg0, 0x70) = 0;
    IP_FIELD(signed char, arg0, 0x3E) = 0;
    IP_FIELD(signed char, arg0, 0x3F) = 0;
    IP_FIELD(float, arg0, 0x8C) = lbl_27_rodata_2CF0;
    IP_FIELD(float, arg0, 0x118) = lbl_27_rodata_2CF0;
    IP_FIELD(signed char, arg0, 0x41) = -1;
    IP_FIELD(signed char, arg0, 0x40) = 0;
    IP_FIELD(float, arg0, 0x78) = lbl_27_rodata_2CF0;
    IP_FIELD(float, arg0, 0x7C) = lbl_27_rodata_2CF0;
    IP_FIELD(float, arg0, 0x80) = lbl_27_rodata_2CF0;
    IP_FIELD(signed char, arg0, 0x77) = 0;
    IP_FIELD(signed char, arg0, 0x76) = 0;
    return arg0;
}
