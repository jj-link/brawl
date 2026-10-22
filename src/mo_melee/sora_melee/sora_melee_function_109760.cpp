#pragma force_active on
extern "C" {
int fn_27_119124(void*, int);
int getEntity__14ftEntryManagerFUl(void*, unsigned);
unsigned char fn_27_149BD8(int, int*);
int fn_27_12131C(void*, int, int, int, int, int, int);
int fn_27_1132A4(int, int, int*, void*, int, int, void*);
int fn_8004F294(int);
void OSReport(const char*, ...);
extern unsigned char lbl_27_rodata_12B0[];
extern unsigned char lbl_27_rodata_12E8[];
extern char lbl_27_data_26134[];
extern char lbl_27_data_26168[];
struct Slot { char pad[0x159]; unsigned char c; };
struct SM { Slot* slots; };
extern SM* g_ftSlotManager;

int fn_27_109760(char* self, char* a) {
    int sp[4];
    int f = 0;
    int t = *(int*)(a + 8);
    if (t >= 0x2e && t <= 0x31) f = 1;
    int id = fn_27_119124(*(void**)(self + 0x154), f == 0);
    if (id == -1) return -1;
    int ent = getEntity__14ftEntryManagerFUl(*(void**)(self + 0x154), id);
    unsigned char r = fn_27_149BD8(*(int*)(a + 8), sp);
    int fl = 0x102;
    unsigned char k = *(unsigned char*)(a + 0x23);
    if (k == 1) {
        if (lbl_27_rodata_12B0[sp[*(unsigned char*)(a + 0x22)]]) fl |= 0x2000;
    } else if (k == 6) {
        if (lbl_27_rodata_12E8[sp[*(unsigned char*)(a + 0x22)]]) fl |= 0x4000;
    }
    int s = fn_27_12131C(g_ftSlotManager, *(int*)(a + 8), *(unsigned char*)(a + 0x20), *(unsigned char*)(a + 0x22), fl, *(int*)(a + 0x18), (f == 0) ? 0 : 4);
    if (s == -1) OSReport(lbl_27_data_26134, *(int*)(a + 4));
    char* sl = (char*)g_ftSlotManager->slots + s * 0x4d4;
    sl[0x159]++;
    fn_27_1132A4(ent, r, sp, a, s, *(int*)(sl + 0x164), sl);
    int t2 = *(int*)(a + 8);
    OSReport(lbl_27_data_26168, id, t2, fn_8004F294(t2), *(unsigned char*)(a + 0x20), s);
    return id;
}
}
