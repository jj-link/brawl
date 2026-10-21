#pragma force_active on
extern int lbl_80487508[];

extern "C" {
void fn_802D1588(void* arg0) {
    if (arg0) {
        *(short*)((char*)arg0 + 6) = 1;
        *(int*)arg0 = (int)lbl_80487508;
    }
}
}
