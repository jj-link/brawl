#pragma force_active on
struct RobotStorage {
    void* primary;
    void* secondary;
};

struct RobotRegistration {
    void* next;
    void* object;
    void* destructor;
};

class RobotView {
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
extern signed char lbl_120_bss_384;
extern RobotStorage lbl_120_bss_388;
extern RobotRegistration lbl_120_bss_3C0;
extern unsigned char lbl_120_data_266C[];
extern unsigned char lbl_120_data_2640[];
extern unsigned char lbl_120_data_25D8[];
extern unsigned char lbl_120_data_78D8[];

void __register_global_object(void*, void*, void*);
void* fn_120_13B80(void*, short);

void fn_120_15F54() {
    if (lbl_120_bss_384 == 0) {
        lbl_120_bss_388.primary = lbl_120_data_266C;
        lbl_120_bss_388.secondary = lbl_120_data_2640;
        lbl_120_bss_388.primary = lbl_120_data_25D8;
        lbl_120_bss_388.secondary = lbl_120_data_25D8 + 0x10;
        lbl_120_bss_388.primary = lbl_120_data_78D8;
        lbl_120_bss_388.secondary = lbl_120_data_78D8 + 0x10;

        __register_global_object(&lbl_120_bss_388,
                                 reinterpret_cast<void*>(fn_120_13B80),
                                 &lbl_120_bss_3C0);
        lbl_120_bss_384 = 1;
    }

    reinterpret_cast<RobotView*>(&lbl_120_bss_388)->dispatch();
}
}
