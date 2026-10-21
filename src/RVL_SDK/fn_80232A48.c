#pragma force_active on
typedef unsigned char u8;

void fn_8023BDCC(u8, int, int);
void fn_8023C248(u8, int, int);

void fn_80232A48(u8 *arg0) {
    fn_8023BDCC(arg0[0x8], 0, 0);
    fn_8023C248(arg0[0x9], 0, 0);
}
