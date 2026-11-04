#pragma force_active on
extern "C" {
void* fn_803F602C(void* dst, const void* src, unsigned int n);
int fn_801478E8(void* arg0, unsigned char arg1);
void fn_800D353C(int task);
}

extern int g_muWifiInterfaceTask;
extern int lbl_805A0434;

extern "C" void fn_14_13CC(unsigned char* self, unsigned int idx) {
    unsigned char* p;
    unsigned char* slot = self + ((idx << 7) & 0x7F80);
    unsigned char* dst = slot + 0x2B8;
    unsigned char r31 = slot[0x2B8];
    int r6 = *(int*)(self + 0x24C0) - (int)idx - 1;
    int count;
    int j;
    int k;
    int task;

    if (r6 > 0) {
        fn_803F602C(dst, self + ((idx + 1) << 7) + 0x2B8, r6 << 7);
    }

    count = *(int*)(self + 0x24C0);
    for (j = 0; j < count; j++) {
        if (idx == self[0x22B8 + j]) {
            break;
        }
    }

    if (count - j - 1 > 0) {
        fn_803F602C(self + 0x22B8 + j, self + 0x22B9 + j, count - j - 1);
    }

    *(int*)(self + 0x24C0) = *(int*)(self + 0x24C0) - 1;

    for (k = 0; k < *(int*)(self + 0x24C0); k++) {
        p = self + k;
        if (p[0x22B8] >= idx) {
            p[0x22B8] = (unsigned char)(p[0x22B8] - 1);
        }
    }

    if (self[0x40] == 0) {
        task = g_muWifiInterfaceTask;
        fn_801478E8((void*)lbl_805A0434, r31);
        fn_800D353C(task);
    }
}
