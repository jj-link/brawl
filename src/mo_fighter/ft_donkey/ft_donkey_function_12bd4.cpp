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
extern signed char lbl_92_bss_304;
extern Storage lbl_92_bss_308;
extern Registration lbl_92_bss_2A4;
extern unsigned char lbl_92_data_1CD8[], lbl_92_data_1CAC[];
extern unsigned char lbl_92_data_1C44[], lbl_92_data_71D0[];
void* fn_92_12938(void*, short);
void __register_global_object(void*, void*, void*);
void fn_92_12BD4(void) {
    if (lbl_92_bss_304 == 0) {
        lbl_92_bss_308.primary = lbl_92_data_1CD8;
        lbl_92_bss_308.secondary = lbl_92_data_1CAC;
        lbl_92_bss_308.primary = lbl_92_data_1C44;
        lbl_92_bss_308.secondary = lbl_92_data_1C44 + 0x10;
        lbl_92_bss_308.primary = lbl_92_data_71D0;
        lbl_92_bss_308.secondary = lbl_92_data_71D0 + 0x10;
        __register_global_object(&lbl_92_bss_308, reinterpret_cast<void*>(fn_92_12938), &lbl_92_bss_2A4);
        lbl_92_bss_304 = 1;
    }
    reinterpret_cast<View*>(&lbl_92_bss_308)->dispatch();
}
}
