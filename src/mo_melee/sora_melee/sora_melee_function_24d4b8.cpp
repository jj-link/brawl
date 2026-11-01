#pragma force_active on

extern "C" {
extern char lbl_27_rodata_4028[];
void fn_27_249E78(void*, void*, void*);
unsigned int __cvt_fp2unsigned(float);
}

extern "C" void fn_27_24D4B8(void* self) {
    char* elem = (char*)0;
    float scale2 = *(float*)(lbl_27_rodata_4028 + 0x24);
    int offset;
    char* ptr = (char*)self;
    int i = 0;
    float scale1 = *(float*)(lbl_27_rodata_4028 + 0x20);
    float threshold = *(float*)(lbl_27_rodata_4028 + 0x1C);
    offset = 0;

    while (i < *(int*)((char*)self + 0x104)) {
        void* ref = *(void**)((char*)self + 0x44);
        elem = (char*)*(void**)((char*)self + 0xCC) + offset;
        float val = *(float*)((char*)ref + 0x50);

        if (threshold != val) {
            *(unsigned int*)(elem + 0x204) *= 2;
            *(unsigned int*)(elem + 0x208) *= 2;
            *(unsigned int*)(elem + 0x20C) *= 2;
            *(unsigned int*)(elem + 0x23C) *= 2;
            *(unsigned int*)(elem + 0x240) *= 2;
            *(float*)(elem + 0x2C8) *= scale1;
            *(float*)(elem + 0x2CC) *= scale1;

            ref = *(void**)((char*)self + 0x44);
            val = *(float*)((char*)ref + 0x50);

            if (threshold < val) {
                *(unsigned int*)(elem + 0x204) /= 3;
                *(unsigned int*)(elem + 0x208) /= 3;
                *(unsigned int*)(elem + 0x20C) /= 3;
                *(unsigned int*)(elem + 0x23C) /= 3;
                *(unsigned int*)(elem + 0x240) /= 3;
                *(float*)(elem + 0x2C8) *= scale2;
                *(float*)(elem + 0x2CC) *= scale2;
            }

            *(unsigned int*)(elem + 0x234) =
                __cvt_fp2unsigned(*(float*)(elem + 0x2C8));
            *(unsigned int*)(elem + 0x238) =
                __cvt_fp2unsigned(*(float*)(elem + 0x2CC));
        }

        if (i < 4) {
            fn_27_249E78(self, *(void**)(ptr + 0x15C), elem + 0x58);
            fn_27_249E78(self, *(void**)(ptr + 0x15C), elem + 0xBC);
            fn_27_249E78(self, *(void**)(ptr + 0x178), elem + 0x120);
            fn_27_249E78(self, *(void**)(ptr + 0x178), elem + 0x184);
        }

        offset += 0x2AC;
        ptr += 4;
        i++;
    }
}
