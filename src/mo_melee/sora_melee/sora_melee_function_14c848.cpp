#include <ft/ft_common_data_accesser.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void isNull();
    virtual void fn_27_14B698();
    virtual void fn_27_14B6D8();
    virtual void fn_27_14CA0C();
    virtual void fn_27_14CA8C();
    virtual void fn_27_14CAB0();
    virtual void fn_27_14CC78();
    virtual void fn_27_14C9A0();
    virtual void fn_27_14CC70();
    virtual void fn_27_14CC68();
    virtual void fn_27_14BCDC();
    virtual void fn_27_14CC10();
    virtual void fn_27_14C9F4();
    virtual void fn_27_14CA04();
    virtual float fn_27_14C1FC();
};

extern "C" void fn_27_14C848(Class_1250* obj) {
    float* factors = *(float**)((char*)g_ftCommonData.dataCommon + 0x3C);
    char* p = (char*)obj;
    for (int i = 0; i < 2; ++i, p += 0x1c8) {
        *(float*)(p + 0x48) *= factors[1];
        *(float*)(p + 0x54) *= factors[2];
        *(float*)(p + 0x70) *= factors[3];
        *(float*)(p + 0x74) *= factors[4];
        *(float*)(p + 0x90) *= factors[5];
        *(float*)(p + 0xB8) *= factors[6];
        *(float*)(p + 0xFC) *= factors[7];
        *(float*)(p + 0x160) *= factors[8];
    }
    *(float*)((char*)obj + 0x690) = factors[0] * obj->fn_27_14C1FC();
}
