#pragma force_active on
extern "C" {

struct globalObj {
    void* m_0;
    void* m_4;
    void* m_8;
};

extern struct globalObj lbl_8049E594;
extern struct globalObj lbl_8049E588;
extern void fn_80137FF0(void);
extern void* __register_global_object(void*, void*, void*);

void fn_80137FB8() {
    lbl_8049E594.m_4 = 0;
    void* p = &lbl_8049E594.m_4;
    lbl_8049E594.m_8 = 0;
    lbl_8049E594.m_0 = 0;
    lbl_8049E594.m_4 = p;
    lbl_8049E594.m_8 = p;
    __register_global_object(&lbl_8049E594, (void*)&fn_80137FF0, &lbl_8049E588);
}

}

__declspec(section ".ctors") extern void* const fn_80137FB8_ctor = (void*)fn_80137FB8;
