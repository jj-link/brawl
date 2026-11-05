#pragma force_active on
#pragma opt_propagation off

extern "C" void fn_6_1134(void*);
extern "C" void fn_800FABEC(void*);
extern "C" void fn_800FAC58(void*, const void*, int, int);
extern "C" unsigned char lbl_7_data_0[];

extern "C" void fn_7_214(char* self)
{
    int zero;
    unsigned long base = (unsigned long)lbl_7_data_0;
    fn_6_1134(self);
    char* data = *(char**)(self + 0x1AC);
    const void* p = (void*)(base + 0x18);
    fn_800FABEC(data + 0x14);
    zero = 0;
    *(int*)data = zero;
    *(unsigned char*)(data + 0x2C) = zero;
    fn_800FAC58(data + 0x14, p, 0x2B, 0);
    data = *(char**)(self + 0x1AC);
    const void* p2 = (void*)(base + 0x38);
    fn_800FABEC(data + 0xB0);
    *(int*)(data + 0x9C) = zero;
    *(unsigned char*)(data + 0xC8) = zero;
    fn_800FAC58(data + 0xB0, p2, 0x2B, 0);
    fn_800FAC58(*(char**)(self + 0x1AC) + 0x1C80, (void*)(base + 0x50), 0x2B, 0);
    fn_800FAC58(*(char**)(self + 0x1AC) + 0x1C98, (void*)(base + 0x68), 0x2B, 0);
    fn_800FAC58(*(char**)(self + 0x1AC) + 0x1D1C, (void*)(base + 0x84), 0x2B, 0);
}
