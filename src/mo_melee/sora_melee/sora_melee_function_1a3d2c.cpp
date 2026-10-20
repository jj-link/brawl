#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_361C0[];

void fn_27_1A3D2C(void* self) {
    unsigned int* p = (unsigned int*)self;
    unsigned int flag = p[2];
    unsigned char* base = lbl_27_data_361C0;
    p[0] = (unsigned int)base;
    p[1] = (unsigned int)(base + 0x48);
    p[2] = flag & 1;
}
}
