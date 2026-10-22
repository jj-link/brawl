#pragma force_active on

extern "C" {
void fn_800B20B0(void* obj, int enabled);
void fn_800B21C4(void* obj, int enabled);
void fn_80108B70(void* self, void* a, int b, void* c);
void fn_80108C58(void* self, void* a, int b);

extern char lbl_80409310[];
extern char lbl_80409330[];

void fn_80108AE0(void** arg0, void* arg1) {
    void** var_r29 = arg0;
    void* temp_r31;
    int var_r30;
    fn_80108B70(arg0, lbl_80409310, 4, arg1);
    fn_80108C58(arg0, lbl_80409330, 3);
    var_r30 = 0;
    do {
        temp_r31 = *var_r29;
        fn_800B20B0(temp_r31, 1);
        fn_800B21C4(temp_r31, 1);
        var_r30 += 1;
        var_r29 += 1;
    } while (var_r30 < 2);
}
}
