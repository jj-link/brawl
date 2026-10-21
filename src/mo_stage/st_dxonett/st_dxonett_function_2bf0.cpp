#pragma force_active on
typedef unsigned char u8;

extern "C" {
    extern const float lbl_78_rodata_9C;
    extern const float lbl_78_rodata_A4;
    extern int lbl_78_data_C70[];
    extern int lbl_78_data_C74[];
    bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(void*, void*, int);
}

extern "C" void fn_78_2BF0(void* ths, void* collStatus, int unused, unsigned int flag)
{
    char* self = (char*)ths;
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)(unsigned long)lbl_78_data_C70) == 1 ||
        isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)(unsigned long)lbl_78_data_C74) == 1) {
        if (flag == 1) {
            *(u8*)(self + 0x170) = 1;
            *(float*)(self + 0x16C) = lbl_78_rodata_A4;
        }
        u8 cnt = *(u8*)(self + 0x17C);
        float inc;
        float f = *(float*)(self + 0x174);
        inc = lbl_78_rodata_9C;
        *(u8*)(self + 0x17C) = cnt + 1;
        *(float*)(self + 0x174) = f + inc;
    }
}
