#pragma force_active on
extern "C" {

struct globalObj {
    void* m_0;
    void* m_4;
    void* m_8;
};

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void* __register_global_object(void*, void*, void*);
extern void fn_801BE844(void);
extern struct globalObj lbl_804C1CE8;
extern struct globalObj lbl_804C1CF4;
extern signed char lbl_805A0588;

struct globalObj* fn_801BE7BC(void) {
    int enabled = OSDisableInterrupts();
    if (lbl_805A0588 == 0) {
        void* p;
        lbl_804C1CF4.m_4 = 0;
        lbl_804C1CF4.m_8 = 0;
        lbl_804C1CF4.m_0 = 0;
        p = &lbl_804C1CF4.m_4;
        lbl_804C1CF4.m_4 = p;
        lbl_804C1CF4.m_8 = p;
        __register_global_object((void*)&lbl_804C1CF4, (void*)fn_801BE844, (void*)&lbl_804C1CE8);
        lbl_805A0588 = 1;
    }
    OSRestoreInterrupts(enabled);
    return &lbl_804C1CF4;
}

}
