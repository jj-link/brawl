#pragma force_active on
extern "C" void** getInstance__12ntFriendInfoFv(void* self);
extern "C" void fn_8014CB1C(void* a, int b);
extern "C" void netReport__FPCce(const char* fmt, ...);
extern char lbl_804587F0[];

extern "C" void fn_800D2164(void* self, int idx, int val) {
    char* p = (char*)*getInstance__12ntFriendInfoFv(self) + idx * 4;
    *(char*)(p + 0x353) = (char)val;
    fn_8014CB1C(getInstance__12ntFriendInfoFv(p), 1);
    netReport__FPCce(lbl_804587F0, idx, val);
}
