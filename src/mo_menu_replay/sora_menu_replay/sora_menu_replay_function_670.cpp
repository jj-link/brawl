#pragma force_active on
extern "C" {
extern char lbl_7_bss_9;
extern int lbl_7_data_1CC;
extern int lbl_7_data_1E8;
void fn_6_0(void*, int, int);
void fn_800B3C5C(void*, const void*, int);
struct AnimInfo {
float start;
float end;
float rate;
const char* name;
unsigned char flags[4];
};
struct AnimTable {
AnimInfo first[11];
AnimInfo second[11];
unsigned char ids[12];
};
extern AnimTable lbl_7_bss_C;
void fn_7_670(void* arg0, int arg1, int arg2) {
if (lbl_7_bss_9 == 0) {
fn_6_0(&lbl_7_bss_C, lbl_7_data_1CC, lbl_7_data_1E8);
lbl_7_bss_9 = 1;
}
fn_800B3C5C(*(void**)((char*)*(void**)((char*)arg0 + 0x1ac) + 0x108),
&lbl_7_bss_C.first[lbl_7_bss_C.ids[arg1]], 0);
if (arg2 != 0) {
fn_800B3C5C(*(void**)((char*)*(void**)((char*)arg0 + 0x1ac) + 0x160),
&lbl_7_bss_C.second[lbl_7_bss_C.ids[arg1]], 0);
}
*(int*)((char*)*(void**)((char*)arg0 + 0x1ac) + 0x1bf0) = arg1;
}
}