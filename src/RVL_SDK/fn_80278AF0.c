#pragma force_active on
extern char lbl_80485EE0[];

void fn_80278AF0(void* p) {
    int* ptr = (int*)p;
    ptr[0x20 / 4] = 0;
    ptr[0x0 / 4] = (int)lbl_80485EE0;
    ptr[0x24 / 4] = 0;
}
