#pragma force_active on
typedef unsigned long long u64;
typedef struct { int v[10]; } Cal;
typedef struct { char pad[0x10]; u64 t; } St;
extern St lbl_8048E680;
extern u64 OSGetTime(void);
extern void fn_801E1D80(u64, Cal*);

void fn_80358D94(int* a, int* b) {
    Cal c;
    fn_801E1D80(OSGetTime() - lbl_8048E680.t, &c);
    a[0] = c.v[3];
    a[1] = c.v[4];
    a[2] = c.v[5];
    a[3] = c.v[6];
    a[4] = c.v[7];
    b[0] = c.v[0];
    b[1] = c.v[1];
    b[2] = c.v[2];
    b[3] = c.v[8];
    b[4] = c.v[9];
}
