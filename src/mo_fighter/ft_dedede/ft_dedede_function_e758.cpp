#pragma force_active on
// fn_117_E758 is the minimal constructor of the ftDededeStatusUniqProcess
// SpecialSuperJump status object: it just records the class vtable
// (lbl_117_data_84E4, whose typeinfo pointer at +0x00 targets
// lbl_117_data_855C / name string "ftDededeStatusUniqProcessSpecialSuperJump")
// at the head of the object. Original words at .text[0xE758,0xE768):
// 3C800000 38840000 90830000 4E800020, with R_PPC_ADDR16_HA at 0xE75A and
// R_PPC_ADDR16_LO at 0xE75E, both against .data + 0x84E4.
extern "C" {
extern unsigned char lbl_117_data_84E4[];

void fn_117_E758(void* object) {
    *static_cast<void**>(object) = lbl_117_data_84E4;
}
}
