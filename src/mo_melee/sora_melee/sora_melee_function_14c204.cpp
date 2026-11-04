#include <ft/ft_common_data_accesser.h>
#pragma force_active on

class soNullableVt {
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
    virtual void slot11();
    virtual void slot12();
};

extern "C" float fn_27_195388(float, float, float);
extern "C" const float lbl_27_rodata_18D0;

extern "C" void fn_27_14C204(soNullableVt* self, float farg0)
{
    char* a28 = (char*)self + 0x28;
    char* a34 = (char*)self + 0x34;
    char* a3ac = (char*)self + 0x3AC;
    char* a48 = (char*)self + 0x48;
    char* a54 = (char*)self + 0x54;
    char* a70 = (char*)self + 0x70;
    char* a74 = (char*)self + 0x74;
    char* a80 = (char*)self + 0x80;
    char* a84 = (char*)self + 0x84;
    char* a88 = (char*)self + 0x88;
    char* a90 = (char*)self + 0x90;
    char* ab8 = (char*)self + 0xB8;
    char* ad0 = (char*)self + 0xD0;
    char* af8 = (char*)self + 0xF8;
    char* afc = (char*)self + 0xFC;
    char* a118 = (char*)self + 0x118;
    char* a11c = (char*)self + 0x11C;
    char* a190 = (char*)self + 0x190;
    char* a3d4 = (char*)self + 0x3D4;
    char* a138 = (char*)self + 0x138;
    char* a13c = (char*)self + 0x13C;
    char* a140 = (char*)self + 0x140;
    char* a144 = (char*)self + 0x144;
    char* a148 = (char*)self + 0x148;
    char* a14c = (char*)self + 0x14C;
    char* a150 = (char*)self + 0x150;
    char* a1d0 = (char*)self + 0x1D0;
    char* a1d4 = (char*)self + 0x1D4;
    float* tbl = *(float**)((char*)g_ftCommonData.dataCommon + 0x34);
    int i = 0;
    do {
        *(float*)a28 = fn_27_195388(*(float*)a28, farg0, tbl[4]);
        *(float*)a34 = fn_27_195388(*(float*)a34, farg0, tbl[5]);
        *(int*)a3ac = (int)fn_27_195388((float)*(int*)a3ac, farg0, tbl[6]);
        *(float*)a48 = fn_27_195388(*(float*)a48, farg0, tbl[7]);
        *(float*)a54 = fn_27_195388(*(float*)a54, farg0, tbl[8]);
        *(float*)a70 = fn_27_195388(*(float*)a70, farg0, tbl[9]);
        *(float*)a74 = fn_27_195388(*(float*)a74, farg0, tbl[10]);
        *(float*)a80 = fn_27_195388(*(float*)a80, farg0, tbl[11]);
        *(float*)a84 = fn_27_195388(*(float*)a84, farg0, tbl[12]);
        *(float*)a88 = fn_27_195388(*(float*)a88, farg0, tbl[13]);
        *(float*)a90 = fn_27_195388(*(float*)a90, farg0, tbl[14]);
        *(float*)ab8 = fn_27_195388(*(float*)ab8, farg0, tbl[15]);
        *(float*)ad0 = fn_27_195388(*(float*)ad0, farg0, tbl[16]);
        *(float*)af8 = fn_27_195388(*(float*)af8, farg0, tbl[17]);
        *(float*)afc = fn_27_195388(*(float*)afc, farg0, tbl[18]);
        *(float*)a118 = fn_27_195388(*(float*)a118, farg0, tbl[19]);
        *(float*)a11c = fn_27_195388(*(float*)a11c, farg0, tbl[20]);
        *(float*)a190 = fn_27_195388(*(float*)a190, farg0, tbl[21]);
        *(int*)a3d4 = (int)fn_27_195388((float)*(int*)a3d4, farg0, tbl[22]);
        *(float*)a138 = fn_27_195388(*(float*)a138, farg0, tbl[23]);
        *(float*)a13c = fn_27_195388(*(float*)a13c, farg0, tbl[24]);
        *(float*)a140 = fn_27_195388(*(float*)a140, farg0, tbl[25]);
        *(float*)a144 = fn_27_195388(*(float*)a144, farg0, tbl[26]);
        *(float*)a148 = fn_27_195388(*(float*)a148, farg0, tbl[27]);
        *(float*)a14c = fn_27_195388(*(float*)a14c, farg0, tbl[28]);
        *(float*)a150 = fn_27_195388(*(float*)a150, farg0, tbl[29]);
        *(float*)a1d0 = fn_27_195388(*(float*)a1d0, farg0, tbl[30]);
        *(float*)a1d4 = fn_27_195388(*(float*)a1d4, farg0, tbl[31]);
        a28 += 0x1C8;
        a34 += 0x1C8;
        a3ac += 0x6C;
        a48 += 0x1C8;
        a54 += 0x1C8;
        a70 += 0x1C8;
        a74 += 0x1C8;
        a80 += 0x1C8;
        a84 += 0x1C8;
        a88 += 0x1C8;
        a90 += 0x1C8;
        ab8 += 0x1C8;
        ad0 += 0x1C8;
        af8 += 0x1C8;
        afc += 0x1C8;
        a118 += 0x1C8;
        a11c += 0x1C8;
        a190 += 0x1C8;
        a3d4 += 0x6C;
        a138 += 0x1C8;
        a13c += 0x1C8;
        a140 += 0x1C8;
        a144 += 0x1C8;
        a148 += 0x1C8;
        a14c += 0x1C8;
        a150 += 0x1C8;
        a1d0 += 0x1C8;
        a1d4 += 0x1C8;
        i++;
    } while (i < 2);
    fn_27_195388(lbl_27_rodata_18D0, farg0, tbl[1]);
    self->fn_27_14BCDC();
}
