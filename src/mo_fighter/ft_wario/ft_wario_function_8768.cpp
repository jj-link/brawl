#pragma force_active on
extern "C" void fn_27_197E94(void*, int, int);
extern "C" void* fn_27_14DFE4(void*, int, int, int, int, int, int, int, int);
extern "C" void fn_27_A78C0(void*);
extern "C" void fn_27_1991F0(void*, int);
extern "C" void fn_27_CA114(void*, int);

extern "C" void* fn_110_8768(void* self, int a2, int a3, int a4) {
    fn_27_197E94(self, 1, 0);
    fn_27_14DFE4((char*)self + 0x10, a2, a3 & 0xff,
                 (int)self + 0x220, (int)self + 0x94, (int)self + 0x78,
                 (int)self, a4, 8);
    fn_27_A78C0((char*)self + 0x78);
    fn_27_1991F0((char*)self + 0x94, 0);
    fn_27_CA114((char*)self + 0x220, 0);
    return self;
}
