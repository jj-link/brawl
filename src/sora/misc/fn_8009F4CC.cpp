#pragma force_active on
extern "C" {

struct globalObj {
    void* m_0;
    void* m_4;
    void* m_8;
};

extern struct globalObj lbl_8049DEDC;
extern struct globalObj lbl_8049DED0;
extern void fn_8009F504(void*);
extern void* __register_global_object(void*, void*, void*);

void fn_8009F4CC() {
    lbl_8049DEDC.m_4 = 0;
    void* p = &lbl_8049DEDC.m_4;
    lbl_8049DEDC.m_8 = 0;
    lbl_8049DEDC.m_0 = 0;
    lbl_8049DEDC.m_4 = p;
    lbl_8049DEDC.m_8 = p;
    __register_global_object(&lbl_8049DEDC, (void*)&fn_8009F504, &lbl_8049DED0);
}

}

__declspec(section ".ctors") extern void* const fn_8009F4CC_ctor = (void*)fn_8009F4CC;
