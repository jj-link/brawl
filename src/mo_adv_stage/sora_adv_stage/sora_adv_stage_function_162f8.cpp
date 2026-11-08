#pragma force_active on
struct S { int v[10]; };
struct O { char pad[0xac]; int id; int getId() const { return id; } };
extern "C" O* fn_40_15694(int, int);
extern "C" S lbl_40_data_3528;
extern "C" int fn_40_162F8(int x, int y) {
    S a = lbl_40_data_3528;
    O* p = fn_40_15694(x, y);
    for (int i = 0; i < 10; i++) {
        if (p && a.v[i] == p->getId()) return 1;
    }
    return 0;
}