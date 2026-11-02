#pragma force_active on
extern "C" void fn_801F55EC(int);
extern "C" void fn_801ACB68(void*);
extern "C" void fn_801ACBB4(void*);
extern "C" void fn_801ACBD0(void*);
extern "C" void fn_801AC5EC(void*, int);
extern "C" void* fn_801AC554(void*, int);
extern "C" void fn_80018EC4(void*, void*);
extern "C" void fn_801ACBEC(void*);
extern "C" void fn_801ACC64(void*);
extern "C" void fn_801ACD50(void*);
extern "C" void* getManager__15gfCameraManagerFv();
extern int lbl_2_rodata_210;

struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void fn_2_8228();
    virtual void fn_2_8310();
    virtual void fn_2_8388();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_2_8148();
    virtual void fn_2_8400();
};

extern "C" void fn_2_8228(char* root) {
    void* obj;
    char* dst;
    int off;
    int* p;
    int i;
    fn_801F55EC(0);
    p = &lbl_2_rodata_210;
    i = 0;
    off = 0;
    for (; i < 2; i++) {
        char* base = *reinterpret_cast<char**>(root + 0x40);
        obj = *reinterpret_cast<void**>(base + off);
        if (obj != 0) {
            fn_801ACB68(obj);
            fn_801ACBB4(obj);
            fn_801ACBD0(obj);
            fn_801AC5EC(obj, 0);
            char* cam = (char*)getManager__15gfCameraManagerFv();
            dst = cam + *p * 0x134;
            void* sp8 = fn_801AC554(obj, 0);
            fn_80018EC4(dst, &sp8);
            fn_801ACBEC(obj);
            fn_801ACC64(obj);
            fn_801ACD50(obj);
        }
        off += 8;
        p++;
    }
    Class_728* self = (Class_728*)root;
    self->fn_2_8400();
}
