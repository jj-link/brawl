#pragma force_active on
extern "C" {

void fn_27_11CA3C(void* a, int b, int c, int d, unsigned char e, int* f);
void fn_27_11D534(void* a, int b);
unsigned char fn_27_149BD8(int a, int* b);

inline int findSlot(void* self, int count, int index) {
    for (int n = 0; n < count; n++) {
        if ((*(unsigned char**)self)[index * 0x4D4 + 0x15D] == 1) {
            return index;
        }
        index++;
        if (index >= count) {
            index = 0;
        }
    }
    return -1;
}

inline int findPreferred(void* self, int index) {
    if (index != -1 && index < *(int*)((unsigned char*)self + 4) &&
        (*(unsigned char**)self + index * 0x4D4)[0x15D] == 1) {
        return index;
    }
    return findSlot(self, *(int*)((unsigned char*)self + 4), 0);
}

int fn_27_12163C(void* self, int arg1, int arg2, int arg3, int arg4) {
    int sp8;
    int r27;
    int r26;
    int off;
    unsigned char* p;
    int count;
    int i;
    int k;
    int ok;
    unsigned char r;

    ok = 0;
    if (arg1 >= 0x2E && arg1 <= 0x31) {
        ok = 1;
    }
    if (ok != 0) {
        count = *(int*)((unsigned char*)self + 4);
        for (i = 4, off = 0x1350; i < count; off += 0x4D4, i++) {
            p = *(unsigned char**)self + off;
            if (p[0x15D] == 0 && arg1 == *(int*)(p + 0x160)) {
                return i;
            }
        }
        if (count > 4 && (*(unsigned char**)self)[0x14AD] == 1) {
            r26 = 4;
        } else {
            r26 = findSlot(self, count, 4);
        }
    } else {
        r26 = findPreferred(self, arg4);
    }
block_31:
    r = fn_27_149BD8(arg1, &sp8);
    r27 = r26 * 0x4D4;
    fn_27_11CA3C((unsigned char*)*(unsigned char**)self + r27, arg1, arg2, arg3, r, &sp8);
    fn_27_11D534((unsigned char*)*(unsigned char**)self + r27, arg3);
    return r26;
}

}
