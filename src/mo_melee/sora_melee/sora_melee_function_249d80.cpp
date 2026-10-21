#pragma force_active on

typedef unsigned char u8;

extern "C" void fn_27_247EF4(void*, int, int);

extern "C" void fn_27_249D80(void* self, int a, int b)
{
    u8* p = (u8*)self;
    if (!p[0x74]) {
        u8* map = *(u8**)(p + 0x44) + 0x9B;
        u8* base = *(u8**)(p + 0xCC) + 0x24;
        u8* first = base + map[a * 0x5C] * 0x2AC;
        u8* second = base + map[b * 0x5C] * 0x2AC;

        int i = (*(int*)(p + 0x15C + a * 4))++ % 100;
        (first + i)[0x34] = second[0];
        (first + i)[0x98] = second[3];

        int j = (*(int*)(p + 0x178 + b * 4))++ % 100;
        (second + j)[0xFC] = first[0];
        (second + j)[0x160] = first[3];

        fn_27_247EF4(self, a, b);
    }
}
