#pragma force_active on
struct Storage { void* primary; void* secondary; };
struct Registration { void* next; void* object; void* destructor; };
class View {
public:
    virtual void slot00(); virtual void slot01(); virtual void slot02();
    virtual void slot03(); virtual void slot04(); virtual void slot05();
    virtual void dispatch();
};
extern "C" {
extern signed char lbl_104_bss_324;
extern Storage lbl_104_bss_328;
extern Registration lbl_104_bss_2D0;
extern unsigned char lbl_104_data_2868[], lbl_104_data_283C[];
extern unsigned char lbl_104_data_27D4[], lbl_104_data_888C[];
void* fn_104_155E0(void*, short);
void __register_global_object(void*, void*, void*);
void fn_104_15678(void*) {
    if (lbl_104_bss_324 == 0) {
        lbl_104_bss_328.primary = lbl_104_data_2868;
        lbl_104_bss_328.secondary = lbl_104_data_283C;
        lbl_104_bss_328.primary = lbl_104_data_27D4;
        lbl_104_bss_328.secondary = lbl_104_data_27D4 + 0x10;
        lbl_104_bss_328.primary = lbl_104_data_888C;
        lbl_104_bss_328.secondary = lbl_104_data_888C + 0x10;
        __register_global_object(&lbl_104_bss_328, reinterpret_cast<void*>(fn_104_155E0), &lbl_104_bss_2D0);
        lbl_104_bss_324 = 1;
    }
    reinterpret_cast<View*>(&lbl_104_bss_328)->dispatch();
}
}