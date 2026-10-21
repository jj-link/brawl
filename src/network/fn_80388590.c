#pragma force_active on

extern int fn_8035AED0(int, int, int, void*, void*, void*);
extern int fn_80388508(void);
extern int fn_8038857C(const char* const*, const char* const*);
extern int fn_80388588(void);
extern int lbl_805A1120;

int fn_80388590(void) {
    if (lbl_805A1120 == 0) {
        lbl_805A1120 = fn_8035AED0(8, 0x1F4, 4, (void*)&fn_80388508, (void*)&fn_8038857C, (void*)&fn_80388588);
    }
    return lbl_805A1120;
}
