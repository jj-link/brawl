#pragma force_active on
extern void fn_8038AF70(void* p);
extern void fn_80387DF8(void* p);
extern void fn_8035E00C(void* p);

void fn_803895D0(void* arg0) {
    fn_8038AF70((char*)arg0 + 0x4C);
    fn_80387DF8(arg0);
    fn_8035E00C(arg0);
}
