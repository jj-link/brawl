#pragma force_active on
extern char lbl_80488CB8[];

extern "C" {
void fn_80325BB0(void* arg0) {
    if (arg0 != 0) {
        char* p = lbl_80488CB8;
        ((short*)arg0)[3] = 1;
        *(char**)arg0 = p;
    }
}
}
