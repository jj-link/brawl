#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_1_data_62F8[];
extern char lbl_1_data_6400[];

void fn_1_1E5BC(void* self) {
    u32* p = (u32*)self;
    p[0] = (u32)lbl_1_data_62F8;
    p[1] = (u32)lbl_1_data_6400;
    p[10] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[18] = 0;
    p[19] = 0;
    p[2] = 5;
    p[3] = 0;
    p[4] = 0;
    p[5] = 1;
    p[6] = 0;
    p[7] = 0x3f;
    p[8] = 1;
}
}
