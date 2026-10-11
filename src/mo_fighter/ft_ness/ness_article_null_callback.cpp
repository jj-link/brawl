// Borrow only the original primary-table call ABI; no view objects are constructed.
class NessArticleFinishView {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void finish();
};
struct NessArticleNull {
    void* generatorTable;
    void* operatorTable;
};
struct NessArticleRegistration { void* next; void* object; void* destructor; };
extern "C" {
extern signed char lbl_101_bss_2EC;
extern NessArticleNull lbl_101_bss_2F0;
extern NessArticleRegistration lbl_101_bss_278;
extern unsigned char lbl_101_data_3CF4[], lbl_101_data_3CC8[];
extern unsigned char lbl_101_data_3C60[], lbl_101_data_947C[];
void* fn_101_15EA4(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_16258(void*) {
    if (lbl_101_bss_2EC == 0) {
        // Preserve generator/operator base initialization before the concrete tables.
        lbl_101_bss_2F0.generatorTable = lbl_101_data_3CF4;
        lbl_101_bss_2F0.operatorTable = lbl_101_data_3CC8;
        lbl_101_bss_2F0.generatorTable = lbl_101_data_3C60;
        lbl_101_bss_2F0.operatorTable = lbl_101_data_3C60 + 0x10;
        lbl_101_bss_2F0.generatorTable = lbl_101_data_947C;
        lbl_101_bss_2F0.operatorTable = lbl_101_data_947C + 0x10;
        __register_global_object(&lbl_101_bss_2F0,
            reinterpret_cast<void*>(fn_101_15EA4), &lbl_101_bss_278);
        lbl_101_bss_2EC = 1;
    }
    reinterpret_cast<NessArticleFinishView*>(&lbl_101_bss_2F0)->finish();
}
