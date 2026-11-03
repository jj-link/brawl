#pragma force_active on
extern "C" {
extern unsigned char lbl_113_data_A834[];
extern unsigned char lbl_113_data_A8E8[];

void fn_113_227EC(void* arg0, void* arg1, void* arg2) {
    unsigned char* self = static_cast<unsigned char*>(arg0);
    unsigned char* fields = static_cast<unsigned char*>(arg1);

    self[0x04] = 0;
    *(int*)(self + 0x0C) = 0x43;
    *(int*)(self + 0x10) = 0xF9F;
    *(int*)(self + 0x14) = 0x5DBF;
    *(int*)(self + 0x18) = 0;
    *(unsigned char**)(self + 0x08) = lbl_113_data_A834;
    *(unsigned char**)(self + 0x00) = lbl_113_data_A834 + 8;
    *(int*)(self + 0x15C) = 0;
    *(unsigned char**)(self + 0x158) = lbl_113_data_A8E8;
    *(void**)(self + 0x160) = arg2;
    *(int*)(self + 0x164) = 5;
    if (arg2 == 0) {
        *(int*)(self + 0x164) = 0;
    }
    *(unsigned char**)(self + 0x1C) = fields;
    *(unsigned char**)(self + 0x20) = fields + 0x04;
    *(unsigned char**)(self + 0x24) = fields + 0x08;
    *(unsigned char**)(self + 0x28) = fields + 0x0C;
    *(unsigned char**)(self + 0x2C) = fields + 0x10;
    *(unsigned char**)(self + 0x30) = fields + 0x14;
    *(unsigned char**)(self + 0x34) = fields + 0x20;
    *(unsigned char**)(self + 0x38) = fields + 0x24;
    *(unsigned char**)(self + 0x3C) = fields + 0x28;
    *(unsigned char**)(self + 0x40) = fields + 0x2C;
    *(unsigned char**)(self + 0x44) = fields + 0x30;
    *(unsigned char**)(self + 0x48) = fields + 0x34;
    *(unsigned char**)(self + 0x4C) = fields + 0x38;
    *(unsigned char**)(self + 0x50) = fields + 0x40;
    *(unsigned char**)(self + 0x54) = fields + 0x44;
    *(unsigned char**)(self + 0x58) = fields + 0x48;
    *(unsigned char**)(self + 0x5C) = fields + 0x4C;
    *(unsigned char**)(self + 0x60) = fields + 0x50;
    *(unsigned char**)(self + 0x64) = fields + 0x54;
    *(unsigned char**)(self + 0x68) = fields + 0x58;
    *(unsigned char**)(self + 0x6C) = fields + 0x5C;
    *(unsigned char**)(self + 0x70) = fields + 0x60;
    *(unsigned char**)(self + 0x74) = fields + 0x64;
    *(unsigned char**)(self + 0x78) = fields + 0x68;
    *(unsigned char**)(self + 0x7C) = fields + 0x6C;
    *(unsigned char**)(self + 0x80) = fields + 0x7C;
    *(unsigned char**)(self + 0x84) = fields + 0x80;
    *(unsigned char**)(self + 0x88) = fields + 0x88;
    *(unsigned char**)(self + 0x8C) = fields + 0x90;
    *(unsigned char**)(self + 0x90) = fields + 0x94;
    *(unsigned char**)(self + 0x94) = fields + 0x98;
    *(unsigned char**)(self + 0x98) = fields + 0x9C;
    *(unsigned char**)(self + 0x9C) = fields + 0xA0;
    *(unsigned char**)(self + 0xA0) = fields + 0xA4;
    *(unsigned char**)(self + 0xA4) = fields + 0xA8;
    *(unsigned char**)(self + 0xA8) = fields + 0xAC;
    *(unsigned char**)(self + 0xAC) = fields + 0xB0;
    *(unsigned char**)(self + 0x124) = fields + 0x18;
    *(unsigned char**)(self + 0x128) = fields + 0x1C;
    *(unsigned char**)(self + 0x12C) = fields + 0x3C;
    *(unsigned char**)(self + 0x130) = fields + 0x70;
    *(unsigned char**)(self + 0x134) = fields + 0x74;
    *(unsigned char**)(self + 0x138) = fields + 0x78;
    *(unsigned char**)(self + 0x13C) = fields + 0x84;
    *(unsigned char**)(self + 0x140) = fields + 0x8C;
}
}
