#pragma force_active on
extern "C" {
struct Info {
    int a;
    char pad0[4];
    int b;
    char pad1[8];
    int c;
};
int fn_801C6C04(void*, Info*);

unsigned long fn_801C6110(void* arg1, void* self) {
    int var_r31 = 0;
    Info data;
    if (fn_801C6C04(self, &data)) {
        var_r31 = data.a + data.b;
        var_r31 += data.c;
    }
    return var_r31 * 0x18;
}
}
