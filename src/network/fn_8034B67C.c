#pragma force_active on
extern int lbl_805A0FA8;
extern int lbl_804156E0[];
extern int lbl_8048B760[];
extern int lbl_8048CB44[];
int fn_8038993C(int);
int fn_80389934(int, int);
int fn_80388794(int, void *, int);
unsigned int fn_8033652C(int);
void fn_803886C8(int, void *, int);
void fn_80335638(int, ...);
void fn_80389944(int, int, void *, int);
void fn_8034B67C(void) {
    int arr[8];
    int j;
    int *q;
    int i;
    int *tab2;
    int *tab;
    int t, val, cur, d, prev, r;
    unsigned int thr;
    int max = 0;
    int sum = 0;
    if (fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8)) > 1) {
        i = 0;
        tab = lbl_804156E0;
        while (i < fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8))) {
            t = fn_80388794(fn_80389934(*(int *)(lbl_805A0FA8 + 0xF8), i), lbl_8048B760, -1);
            if (t > max) max = t;
            sum += *tab;
            tab++;
            i++;
        }
        thr = fn_8033652C(0x64);
        q = arr;
        tab2 = lbl_804156E0;
        j = 0;
        while (j < fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8))) {
            if (j == fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8)) - 1) {
                arr[j] = 100;
                break;
            }
            cur = *tab2;
            d = (cur * 100) / sum;
            if (j > 0) prev = q[-1];
            else prev = 0;
            val = d + prev;
            *q = val;
            if (thr < (unsigned int)val) break;
            q++;
            tab2++;
            j++;
        }
        fn_80335638(0x40, lbl_8048CB44, j, arr[j], thr);
        if (max < 0x7FFFFFFF) max++;
        r = fn_80389934(*(int *)(lbl_805A0FA8 + 0xF8), j);
        fn_803886C8(r, lbl_8048B760, max);
        fn_80389944(*(int *)(lbl_805A0FA8 + 0xF8), 0, lbl_8048B760, 0);
    }
}