#pragma force_active on
extern int lbl_804E4840[];
void fn_80204E6C(void *a, int b);

void fn_8027E264(int *arg0) {
    fn_80204E6C(lbl_804E4840, (int)arg0 - arg0[-1]);
}
