#include <types.h>
#pragma force_active on

struct LucasArticleMediatorStorage { void* primary; void* secondary; };
struct LucasArticleMediatorRegistration { void* next; void* object; void* destructor; };

class LucasArticleMediatorView {
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
extern signed char lbl_114_bss_2EC;
extern LucasArticleMediatorStorage lbl_114_bss_2F0;
extern LucasArticleMediatorRegistration lbl_114_bss_278;
extern unsigned char lbl_114_data_3640[];
extern unsigned char lbl_114_data_3614[];
extern unsigned char lbl_114_data_35AC[];
extern unsigned char lbl_114_data_8D7C[];
void* fn_114_159F4(void*, short);
void __register_global_object(void*, void*, void*);

void fn_114_15DA8(void* self) {
    if (lbl_114_bss_2EC == 0) {
        lbl_114_bss_2F0.primary = lbl_114_data_3640;
        lbl_114_bss_2F0.secondary = lbl_114_data_3614;
        lbl_114_bss_2F0.primary = lbl_114_data_35AC;
        lbl_114_bss_2F0.secondary = lbl_114_data_35AC + 0x10;
        lbl_114_bss_2F0.primary = lbl_114_data_8D7C;
        lbl_114_bss_2F0.secondary = lbl_114_data_8D7C + 0x10;
        __register_global_object(&lbl_114_bss_2F0,
                                 reinterpret_cast<void*>(fn_114_159F4),
                                 &lbl_114_bss_278);
        lbl_114_bss_2EC = 1;
    }
    reinterpret_cast<LucasArticleMediatorView*>(&lbl_114_bss_2F0)->dispatch();
}
}
