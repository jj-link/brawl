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
extern signed char lbl_111_bss_228;
extern Storage lbl_111_bss_22C;
extern Registration lbl_111_bss_1D4;
extern unsigned char lbl_111_data_1708[], lbl_111_data_16DC[];
extern unsigned char lbl_111_data_1674[], lbl_111_data_6634[];
void* fn_111_10DFC(void*, short);
void __register_global_object(void*, void*, void*);
void fn_111_11098(void*) {
    if (lbl_111_bss_228 == 0) {
        lbl_111_bss_22C.primary = lbl_111_data_1708;
        lbl_111_bss_22C.secondary = lbl_111_data_16DC;
        lbl_111_bss_22C.primary = lbl_111_data_1674;
        lbl_111_bss_22C.secondary = lbl_111_data_1674 + 0x10;
        lbl_111_bss_22C.primary = lbl_111_data_6634;
        lbl_111_bss_22C.secondary = lbl_111_data_6634 + 0x10;
        __register_global_object(&lbl_111_bss_22C, reinterpret_cast<void*>(fn_111_10DFC), &lbl_111_bss_1D4);
        lbl_111_bss_228 = 1;
    }
    reinterpret_cast<View*>(&lbl_111_bss_22C)->dispatch();
}
}