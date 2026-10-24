#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" char lbl_8042E8D8[];
extern "C" void* g_GameGlobal;
extern "C" int lbl_805A00FC;

extern "C" void fn_8005A6E8(void) {
    void* temp_r3 = (void*)lbl_805A00FC;

    if (temp_r3 != 0) {
        ((int*)temp_r3)[1] = (int)lbl_8042E8D8;
        lbl_805A00FC = 0;
        unsigned char* appData = (unsigned char*)*(int*)g_GameGlobal;
        appData[0x28] &= ~0x20;
        __dl__FPv(temp_r3);
    }
    lbl_805A00FC = 0;
}
