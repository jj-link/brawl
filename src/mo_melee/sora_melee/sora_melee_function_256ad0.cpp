#pragma force_active on
extern "C" {
    void fn_8004B848(void* a1, void* a2);
    void fn_27_241EA4(void* a1, int a2);
    void __dl__FPv(void*);
}

extern struct lbl_27_data_53100_t lbl_27_data_53100;
extern char lbl_27_bss_59E0[];

class ipSwitch {
    char _pad[0x18];
public:
    static ipSwitch* getInstance();
    void* m_18;
};

extern "C" void* fn_27_256AD0(void* arg1, int arg2) {
    if (arg1) {
        *(void**)((char*)arg1 + 0x3c) = &lbl_27_data_53100;
        if (ipSwitch::getInstance()) {
            if (ipSwitch::getInstance()->m_18) {
                fn_8004B848(ipSwitch::getInstance()->m_18, &lbl_27_bss_59E0);
            }
        }
        if (arg1) {
            fn_27_241EA4(arg1, 0);
        }
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
