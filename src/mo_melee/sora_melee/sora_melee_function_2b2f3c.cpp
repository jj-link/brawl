#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" {
extern unsigned int lbl_27_data_4A000[];
extern unsigned int lbl_27_data_248[];
extern float lbl_27_rodata_5EA0;
}
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28(int, void*, unsigned int, float);
};
extern "C" void fn_27_2B2F3C(void*, char* obj, char* arg, char* event) {
    int kind = *(int*)((char*)__dynamic_cast(*(void**)(obj + 8), 0x3c, lbl_27_data_4A000, lbl_27_data_248, 1) + 0x8c0);
    if (kind == 0x31 || kind == 0x4f) {
        switch (*(unsigned int*)(event + 0x30) & 0x1f) {
        case 5:
            (*(Class_1250**)(*(char**)(obj + 0xd8) + 0x6c))->fn_27_14A28(4, obj, (unsigned int)(arg + 8), lbl_27_rodata_5EA0);
            break;
        case 3:
        case 20:
            (*(Class_1250**)(*(char**)(obj + 0xd8) + 0x6c))->fn_27_14A28(4, obj, (unsigned int)(arg + 12), lbl_27_rodata_5EA0);
            break;
        default:
            (*(Class_1250**)(*(char**)(obj + 0xd8) + 0x6c))->fn_27_14A28(4, obj, 7, lbl_27_rodata_5EA0);
            break;
        }
    }
}