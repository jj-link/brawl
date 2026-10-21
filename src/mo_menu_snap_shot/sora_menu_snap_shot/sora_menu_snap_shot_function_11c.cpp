#pragma force_active on
#pragma opt_propagation off

extern "C" void fn_6_1134(void);
extern "C" void fn_800FABEC(void*);
extern "C" void fn_800FAC58(void*, const void*, int, int);
extern "C" unsigned char lbl_8_data_0[];

inline void initialize(char* p, const void* name)
{
    fn_800FABEC(p + 0x14);
    *(int*)p = 0;
    *(unsigned char*)(p + 0x2C) = 0;
    fn_800FAC58(p + 0x14, name, 0x2B, 0);
}

extern "C" void fn_8_11C(char* self)
{
    unsigned long base = (unsigned long)lbl_8_data_0;
    fn_6_1134();
    const void* name = (void*)(base + 0x18);
    initialize(*(char**)(self + 0x1AC), name);
    const void* name2 = (void*)(base + 0x38);
    initialize(*(char**)(self + 0x1AC) + 0x9C, name2);
    fn_800FAC58(*(char**)(self + 0x1AC) + 0x1C80, (void*)(base + 0x50), 0x2B, 0);
    fn_800FAC58(*(char**)(self + 0x1AC) + 0x1C98, (void*)(base + 0x6C), 0x2B, 0);
}
