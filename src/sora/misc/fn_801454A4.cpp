#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_800D0E58(void*, u8, int, int);
u8 fn_800C8548();
int fn_800C8524();
void fn_800D1314(void*, u8);
void fn_800D55E8(void*);
void fn_80146878(void*, int);
extern char* lbl_805A03A8;
extern char* lbl_805A0434;
extern char* g_muWifiInterfaceTask;
extern char lbl_8045E7E8[];
extern unsigned char lbl_8049EC48[];
extern u8 lbl_8059E744;
extern u8 lbl_8059E745;
extern char g_Network[];
}

struct TopBit { u8 f : 1; u8 rest : 7; };
struct Bit4 { u8 hi : 3; u8 f : 1; u8 lo : 4; };
struct StateWord { int st : 8; int rest : 24; };

extern "C" void fn_801454A4(u8 arg0, int arg1, int arg2) {
    char* base = lbl_8045E7E8;
    (lbl_805A03A8 + arg0 * 0xE50)[0x46] = 1;
    int len = arg2 - 0x10;
    int data = arg1 + 0x10;
    int expected = *(int*)(lbl_805A03A8 + 0x28);
    if (len != expected) {
        netReport__FPCce(base + 0x3D8, arg0, expected, len);
        fn_800C8F68(base + 0x414, arg0, expected, arg2 - 0x10);
        return;
    }
    expected = (int)g_muWifiInterfaceTask;
    OSLockMutex(lbl_8049EC48);
    fn_800D0E58((void*)expected, arg0, data, arg2 - 0x10);
    OSUnlockMutex(lbl_8049EC48);
    char* task = g_muWifiInterfaceTask;
    if (lbl_8059E745 != lbl_8059E744) {
        lbl_8059E745 = lbl_8059E744;
        netReport__FPCce(base + 0x43C, lbl_8059E744);
    }
    lbl_805A0434[0x33CE] = 1;
    char* e = task + arg0 * 0x218;
    if (((TopBit*)(e + 0x280))->f) return;
    ((TopBit*)(e + 0x280))->f = 1;
    if (((TopBit*)(task + 0xFC9))->f && *(long long*)(e + 0x248) == 0) {
        netReport__FPCce(base + 0x478);
    }
    if (arg0 == fn_800C8548()) {
        netReport__FPCce(base + 0x49C);
        task[0xFD3] = arg0;
        u8 j = fn_800C8548();
        char* q;
        if (j == 0xFF) {
            q = 0;
        } else {
            q = task + j * 0x218 + 0x70;
        }
        int flag;
        if (q != 0) {
            flag = ((Bit4*)(q + 0x78))->f;
        } else {
            flag = 1;
        }
        if (flag != 0) {
            netReport__FPCce(base + 0x4C4);
            fn_800C8F68(base + 0x510);
            if (((TopBit*)(task + 0xFC9))->f) {
                if (((StateWord*)(task + 0xFCC))->st < 4) {
                    ((StateWord*)(task + 0xFCC))->st = 5;
                }
            } else {
                fn_80146878(g_Network, 1);
            }
            return;
        }
    } else {
        if (fn_800C8524() != 0) {
            netReport__FPCce(base + 0x52C);
            fn_800D1314(task, arg0);
        } else {
            netReport__FPCce(base + 0x554);
        }
    }
    if ((u8)lbl_805A0434[0x33F6] == 1) {
        netReport__FPCce(base + 0x574);
        return;
    }
    if (((TopBit*)(task + 0xFC9))->f) {
        fn_800D55E8(task);
    }
}
