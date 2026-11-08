#pragma force_active on
typedef int s32;

struct Buf;

extern "C" void fn_802CC7C0(Buf* self, s32 key, s32 value);

extern "C" void fn_802D4EC0(Buf* r3) {
    fn_802CC7C0(r3, 4, 1);
    fn_802CC7C0(r3, 6, 1);
    fn_802CC7C0(r3, 7, 1);
    fn_802CC7C0(r3, 8, 1);
    fn_802CC7C0(r3, 5, 1);
    fn_802CC7C0(r3, 9, 1);
    fn_802CC7C0(r3, 0xe, 1);
    fn_802CC7C0(r3, 0xf, 1);
    fn_802CC7C0(r3, 0xa, 1);
    fn_802CC7C0(r3, 0x10, 2);
    fn_802CC7C0(r3, 0xc, 2);
    fn_802CC7C0(r3, 0xd, 0xc);
    fn_802CC7C0(r3, 0x18, 3);
    fn_802CC7C0(r3, 1, 0x15);
    fn_802CC7C0(r3, 0x17, 0x12);
    fn_802CC7C0(r3, 0x13, 0x12);
}