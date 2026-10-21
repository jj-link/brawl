#pragma force_active on

struct Model {
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
    virtual void v11();
    virtual void v12();
    virtual void detach(void*);
};

struct Resource {
    char pad[0x10];
    void* object;
};

struct Menu {
    char pad0[0x70];
    void* field70;
    char pad74[0xC];
    Resource* field80;
    char pad84[4];
    Resource* field88;
    char pad8C[8];
    Model* field94;
    char pad98[0xBC];
    void* field154;
    char pad158[0x298];
    int field3F0;
    char pad3F4[0x1A];
    unsigned short name[11];
};

extern "C" {
extern void* g_sndSystem;
extern char lbl_16_data_36C8[];

void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void fn_16_4ABC(void*, int, void*, int, int);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_8006BCA8(char*, const void*);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
int fn_800B5854(void*, int, int, int, int);

void fn_16_6120(Menu* self) {
    char buffer[32];
    Model* model = self->field94;
    Resource* resource = self->field80;

    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x27, -1, 0, 0, -1);
    fn_16_4ABC(self, 9, self->name, 10, 1);

    Model* nextModel = self->field94;
    self->field3F0 = 30;
    Resource* nextResource = self->field88;

    nextModel->detach(nextResource->object);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        nextModel, nextResource->object, lbl_16_data_36C8);

    fn_8006BCA8(buffer, self->name);
    printf__5MuMsgFUlPCce(self->field154, 11, buffer);
    fn_800B5854(self->field70, 2, 0x11, 0, 0);

    model->detach(resource->object);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        model, resource->object, lbl_16_data_36C8);
}
}
