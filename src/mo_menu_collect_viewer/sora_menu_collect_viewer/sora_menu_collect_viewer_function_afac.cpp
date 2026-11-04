#pragma force_active on
extern "C" void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern "C" void setFrameNode__8MuObjectFf(void*, float);
extern "C" void setFrameVisible__8MuObjectFf(void*, float);
extern "C" int fn_800B5854(void*, int, int, int, int);
extern float lbl_6_rodata_6E8;
struct Display {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void call(void*, void*);
    char pad[0xe4 - 4];
    void* value;
};
struct ViewerData {
    char pad0[0x40];
    void* object40;
    void* object44;
    char pad48[0x70 - 0x48];
    void* object70;
    Display* object74;
    void* msg;
    char pad7c[0x134 - 0x7c];
    int mode;
    int extra;
    char pad13c[0x164 - 0x13c];
    char text0[0x15];
    char text1[1];
};
extern "C" void fn_6_AFAC(ViewerData* self) {
    printf__5MuMsgFUlPCce(self->msg, 0, self->text0);
    printf__5MuMsgFUlPCce(self->msg, 1, self->text1);
    int mode = self->mode;
    int extra = self->extra;
    void* object = self->object44;
    float frame = lbl_6_rodata_6E8 + (float)mode;
    if (mode == 2) {
        frame += (float)extra;
    }
    setFrameNode__8MuObjectFf(object, frame);
    setFrameVisible__8MuObjectFf(object, frame);
    Display* display = self->object74;
    display->call(display->value, self->object70);
    fn_800B5854(self->object40, 0, 1, 1, 0);
}
