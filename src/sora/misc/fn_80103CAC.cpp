#pragma force_active on
extern "C" int fn_801063BC(void);
extern "C" int fn_80106548(void);

extern "C" int fn_80103CAC(const unsigned int* self)
{
    unsigned char* p = (unsigned char*)self[0xCB];
    if (p == 0 || ((p[0x100] >> 7) & 1) || !((p[0x100] >> 6) & 1)) {
        return 0;
    }
    fn_801063BC();
    return fn_80106548();
}
