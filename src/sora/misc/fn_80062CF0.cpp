#pragma force_active on
extern "C" void fn_80062CF0(char* self, int arg1) {
    if (*(int*)(self + 0x24) != 0) {
        return;
    }
    *(int*)(self + 0x28) = -arg1;
}
