#pragma force_active on

extern "C" {
void fn_2_28EB8(void*);
void fn_2_29DC8(void*, int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
int fn_2_24DD0(int);
int isCharUsable__6muMenuFiii(int);

void fn_2_29840(void* self, int p2, int p3, int p4) {
    int* s = (int*)self;
    s[0x654 / 4] = p2;
    int* r4 = (int*)s[0x650 / 4];
    int* r7 = (int*)s[0x64C / 4];
    s[0x670 / 4] = 0;
    s[0x674 / 4] = 0;
    s[0x678 / 4] = p3;
    s[0x66C / 4] = p4;
    s[0x6A0 / 4] = 0;
    s[0x694 / 4] = 0;
    s[0x698 / 4] = 0;
    s[0x69C / 4] = 0;
    s[0x67C / 4] = r7[0x27C / 4];
    s[0x680 / 4] = r7[0x280 / 4];
    s[0x684 / 4] = r7[0x288 / 4];
    s[0x688 / 4] = r7[0x284 / 4];
    s[0x68C / 4] = r4[0x44 / 4];
    s[0x690 / 4] = r4[0x48 / 4];
    fn_2_28EB8(self);
    fn_2_29DC8(self, 0);
    s[0x6A4 / 4] =
        (int)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(42, 0x90);

    int character;
    int count = 0;
    int i = 0;
    int offset = 0;
    for (; i < 35; ++i) {
        character = fn_2_24DD0(i);
        if (isCharUsable__6muMenuFiii(character)) {
            ++count;
            *(int*)((char*)s[0x6A4 / 4] + offset) = character;
            offset += 4;
        }
    }
    ((int*)s[0x6A4 / 4])[0x8C / 4] = count;
}
}
