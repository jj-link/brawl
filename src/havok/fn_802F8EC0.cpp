#pragma force_active on
extern "C" {
void fn_802F4160();
void fn_802F5624(int);

void fn_802F8EC0(void* arg0, int arg1) {
    if (*(int*)((char*)arg0 + 0x100))
        fn_802F4160();
    fn_802F5624(arg1);
}
}
