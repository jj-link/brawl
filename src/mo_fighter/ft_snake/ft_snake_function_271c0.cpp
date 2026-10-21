#pragma force_active on
struct SnakeMediatorStorage {
    void* primary;
    void* secondary;
};

struct SnakeMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class SnakeMediatorView {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void dispatch();
};

extern "C" {
extern signed char lbl_122_bss_244;
extern SnakeMediatorStorage lbl_122_bss_248;
extern SnakeMediatorRegistration lbl_122_bss_454;
extern unsigned char lbl_122_data_8624[];
extern unsigned char lbl_122_data_85F8[];
extern unsigned char lbl_122_data_8590[];
extern unsigned char lbl_122_data_DFD8[];
void fn_122_18D9C(void*);
void __register_global_object(void*, void*, void*);

void fn_122_271C0() {
    if (lbl_122_bss_244 == 0) {
        lbl_122_bss_248.primary = lbl_122_data_8624;
        lbl_122_bss_248.secondary = lbl_122_data_85F8;
        lbl_122_bss_248.primary = lbl_122_data_8590;
        lbl_122_bss_248.secondary = lbl_122_data_8590 + 0x10;
        lbl_122_bss_248.primary = lbl_122_data_DFD8;
        lbl_122_bss_248.secondary = lbl_122_data_DFD8 + 0x10;
        __register_global_object(&lbl_122_bss_248,
                                 reinterpret_cast<void*>(fn_122_18D9C),
                                 &lbl_122_bss_454);
        lbl_122_bss_244 = 1;
    }
    reinterpret_cast<SnakeMediatorView*>(&lbl_122_bss_248)->dispatch();
}
}
