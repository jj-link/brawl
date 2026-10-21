#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern "C" void* getInstance__12ntFriendInfoFv();
extern "C" void fn_8014CB1C(void*, int);
extern int gUnk805a03d8;
extern char lbl_8045FA34[];

extern "C" void fn_80148280(int arg0) {
    if (gUnk805a03d8 != 7) {
        netReport__FPCce(lbl_8045FA34, arg0);
        fn_8014CB1C(getInstance__12ntFriendInfoFv(), 1);
    }
}
