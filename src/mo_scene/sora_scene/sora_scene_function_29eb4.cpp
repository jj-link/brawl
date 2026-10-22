#pragma force_active on
extern "C" int fn_80055398(int);
extern "C" void fn_800553B8(int);
struct A { int a[5]; };
extern A lbl_1_rodata_D50;

struct S { char pad[0x11]; unsigned char m; };

extern "C" void fn_1_29EB4(S* s) {
    A arr = lbl_1_rodata_D50;
    for (int i = 0; i < 5; i++) {
        int v = arr.a[i];
        if (fn_80055398(v) == 0) {
            int r = 0;
            switch (v) {
            case 0x24: if (s->m == 0) r = 1; break;
            case 0x5A: if (s->m == 1) r = 1; break;
            case 0x17: if (s->m == 2) r = 1; break;
            case 0x67: if (s->m == 3) r = 1; break;
            case 0: if (s->m == 4) r = 1; break;
            }
            if (r != 0) fn_800553B8(v);
        }
    }
}
