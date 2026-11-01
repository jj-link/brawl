#include <mu/adv/mu_adv_seal.h>
#pragma force_active on

extern "C" {
void fn_800ADD1C(void*, int, int);
void fn_800AE4F4(void*);
void fn_800AE200(void*, int, int);
int fn_800AED20(void*, int, int);
void fn_27_2D6974(void*, int, int, int, int);
void fn_27_2C9714(int, short);
void fn_27_2CBB7C(void*, int);
extern muAdvSealTask* lbl_27_bss_7328;
}

extern "C" void fn_27_2CBEF0(u32* arg0, int arg1, int arg2) {
    char* writePtr;
    char* task;
    int bound;
    int i;
    int stored;
    int headMinusOne;
    unsigned int* scanPtr;
    char* self;
    int offset;
    int* target;
    int index;
    char* manager;
    int value;
    int entryCount;
    int scanCount;
    int k;
    char* record;

    self = (char*)arg0;
    task = (char*)lbl_27_bss_7328;

    *(int*)(self + 0x3cb4) = arg2;
    *(int*)(self + 0x3cb0) = arg1;
    fn_800ADD1C(*(void**)(task + 0x6a0), arg1, 0);

    if (*(int*)(self + 0x3cb4) == 4) {
        fn_800AE4F4(*(void**)(task + 0x6a0));
    } else {
        fn_800AE200(*(void**)(task + 0x6a0), *(int*)(self + 0x3cb4), 0);
    }

    stored = 0;
    headMinusOne = -1;
    if (*(unsigned char*)(task + 0x44) == 0) {
        entryCount = *(int*)(task + 0x448c);
        if (entryCount >= 0) {
            headMinusOne = *(int*)(task + entryCount * 0x70c + 0x4b9c) - 1;
        }
    }

    if (*(int*)(self + 0x3cb4) == 4) {
        bound = *(int*)(*(int*)(task + 0x6a0) + 0x2ef8);
    } else {
        bound = *(int*)(*(int*)(task + 0x6a0) + 0xc);
    }

    writePtr = self;
    i = 0;
    offset = 0;

    while (i < bound) {
        scanPtr = (unsigned int*)self;
        if (*(int*)(self + 0x3cb4) == 4) {
            index = i;
        } else {
            index = *(int*)((char*)*(void**)(task + 0x6a0) + 0x1784 + offset);
        }

        manager = *(char**)(task + 0x6a0);
        value = *(int*)(manager + index * 4 + 0x7e4);
        target = (int*)(*(int*)manager + value * 0x64);

        if (headMinusOne < 0 || fn_800AED20(manager, headMinusOne, *target) != 0) {
            scanCount = *(int*)(self + 0x2800);
            k = 0;
            while (k < scanCount) {
                if (*scanPtr == (unsigned int)target) {
                    break;
                }
                ++k;
                scanPtr += 2;
            }

            if (k < scanCount) {
                *(int*)(writePtr + 0x2804) = (int)scanPtr;
                writePtr += 4;
                ++stored;
            }
        }

        ++i;
        offset += 4;
    }

    *(int*)(self + 0x3c04) = stored;
    fn_27_2D6974(self + 0x3c08, stored, 9, 1, 1);

    if (*(int*)(self + 0x3ccc) == 0) {
        value = *(int*)(self + 0x3c40) +
                *(int*)(self + 0x3c3c) * *(int*)(self + 0x3c18);
        if (value < *(int*)((char*)lbl_27_bss_7328 + 0x42dc)) {
            record = *(char**)((char*)lbl_27_bss_7328 + value * 4 + 0x2edc);
            fn_27_2C9714(*(int*)record, *(short*)(record + 4));
        } else {
            fn_27_2C9714(0, -1);
        }
    }

    if (*(int*)(self + 0x3ccc) == 0) {
        fn_27_2CBB7C(self, 0);
    }
}
