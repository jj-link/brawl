#pragma force_active on
struct GameWatchArticleMediatorStorage {
    void* primary;
    void* secondary;
};

struct GameWatchArticleMediatorRegistration {
    void* next;
    void* object;
    void* destructor;
};

class GameWatchArticleMediatorView {
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
extern signed char lbl_107_bss_2A0;
extern GameWatchArticleMediatorStorage lbl_107_bss_2A4;
extern GameWatchArticleMediatorRegistration lbl_107_bss_3BC;
extern unsigned char lbl_107_data_3F7C[];
extern unsigned char lbl_107_data_3F50[];
extern unsigned char lbl_107_data_3EE8[];
extern unsigned char lbl_107_data_9CE8[];
void __register_global_object(void*, void*, void*);
void fn_107_1670C(void*);

void fn_107_1FA54() {
    if (lbl_107_bss_2A0 == 0) {
        lbl_107_bss_2A4.primary = lbl_107_data_3F7C;
        lbl_107_bss_2A4.secondary = lbl_107_data_3F50;
        lbl_107_bss_2A4.primary = lbl_107_data_3EE8;
        lbl_107_bss_2A4.secondary = lbl_107_data_3EE8 + 0x10;
        lbl_107_bss_2A4.primary = lbl_107_data_9CE8;
        lbl_107_bss_2A4.secondary = lbl_107_data_9CE8 + 0x10;
        __register_global_object(&lbl_107_bss_2A4, reinterpret_cast<void*>(fn_107_1670C), &lbl_107_bss_3BC);
        lbl_107_bss_2A0 = 1;
    }
    reinterpret_cast<GameWatchArticleMediatorView*>(&lbl_107_bss_2A4)->dispatch();
}
}
