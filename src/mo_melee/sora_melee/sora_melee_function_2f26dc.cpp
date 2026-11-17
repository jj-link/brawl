#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(void*, int);
};

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_bss_7564[];
extern char lbl_27_data_7F138[];
extern char lbl_27_data_7F144[];
extern char lbl_27_data_7F458[];

void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_2E7828(void*, void*, void*);
void fn_27_2F28D4(void*, void*, void*);
}

extern "C" void* fn_27_2F26DC(void* arg0, int arg1, void* arg2, const int* arg3) {
    void* callbackData[2];
    int params[16];

    char* self = (char*)arg0;
    char* modules;
    int shake;
    Object_vptr_0* build = *(Object_vptr_0**)((char*)arg2 + 4);
    shake = build->slot5();
    int group = build->slot2();

    fn_27_1DC5E8(params, 0x57, arg3, group, 0x1f, shake,
                 *arg3 & 0xff, 0, g_soParamAccesserNull,
                 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_7F138, params[1], params[2],
                 arg1, arg2, self + 0x544, 1);

    modules = self + 0xcc;
    char* p = lbl_27_data_7F458;
    *(void**)(self + 0x3c) = p;
    *(void**)(self + 0x40) = p + 0x64;
    *(void**)(self + 0x48) = p + 0x70;
    *(void**)(self + 0x54) = p + 0x84;
    *(void**)(self + 0x64) = p + 0xdc;
    *(void**)(self + 0x70) = p + 0xec;
    *(void**)(self + 0x7c) = p + 0x100;
    *(void**)(self + 0x88) = p + 0x118;
    *(void**)(self + 0x90) = p + 0x124;
    fn_27_2F28D4(modules, self, params);
    fn_27_2E7828(modules + 0x13a0, modules + 0x478, params);
    fn_27_1D90FC(self);

    char* q = lbl_27_data_7F144;
    *(void**)(self + 0x3c) = q;
    *(void**)(self + 0x40) = q + 0x64;
    *(void**)(self + 0x48) = q + 0x70;
    *(void**)(self + 0x54) = q + 0x84;
    *(void**)(self + 0x64) = q + 0xdc;
    *(void**)(self + 0x70) = q + 0xec;
    *(void**)(self + 0x7c) = q + 0x100;
    *(void**)(self + 0x88) = q + 0x118;
    *(void**)(self + 0x90) = q + 0x124;

    callbackData[0] = lbl_27_bss_7564;
    callbackData[1] = lbl_27_bss_7564;
    Object_vptr_0* callback = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
    callback->slot28(callbackData, 2);

    fn_27_1D8FC8(self, 0);
    return arg0;
}
