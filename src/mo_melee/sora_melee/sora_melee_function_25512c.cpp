#pragma force_active on
extern "C" {
extern unsigned int lbl_27_bss_59C0;
extern char g_Network[];
int fn_8013E3E8(void*, unsigned int);
void fn_27_254CDC(int);

void fn_27_25512C(void* obj, unsigned int self) {
    if (((unsigned char*)obj)[0x49] != 0 && lbl_27_bss_59C0 != 0) {
        *(unsigned int*)((char*)obj + 0x54) = self;
        void* net = *(void**)(g_Network + 0x34);
        if (fn_8013E3E8(net, self & 0xFF) == 0) {
            *(unsigned int*)((char*)obj + 0x5c) = self;
            ((unsigned char*)obj)[0x4a] = 1;
            fn_27_254CDC(0);
        }
    }
}
}
