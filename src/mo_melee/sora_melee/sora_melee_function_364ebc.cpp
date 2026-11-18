#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3();
    virtual int slot4();
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
extern char lbl_27_data_91320[];
extern char lbl_27_data_9132C[];
extern char lbl_27_data_91598[];

void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_2E2754(void*, void*, void*);
void fn_27_36566C(void*, void*, void*);
}

extern "C" void* fn_27_364EBC(void* arg0, int arg1, void* arg2, const int* arg3) {
    int cb[3];
    int params[16];

    char* self = (char*)arg0;
    int t22;
    int t23;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = obj->slot5();
    t22 = obj->slot4();
    int t6 = obj->slot2();

    fn_27_1DC5E8(params, 0x36, arg3, t6, t22, t23,
                 *arg3 & 0xff, -1, g_soParamAccesserNull,
                 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_91320, params[1], params[2],
                 arg1, arg2, self + 0x8d0, 1);

    char* modules = self + 0xcc;
    char* p = lbl_27_data_91598;
    *(void**)(self + 0x3c) = p;
    *(void**)(self + 0x40) = p + 0x64;
    *(void**)(self + 0x48) = p + 0x70;
    *(void**)(self + 0x54) = p + 0x84;
    *(void**)(self + 0x64) = p + 0xdc;
    *(void**)(self + 0x70) = p + 0xec;
    *(void**)(self + 0x7c) = p + 0x100;
    *(void**)(self + 0x88) = p + 0x118;
    *(void**)(self + 0x90) = p + 0x124;
    fn_27_36566C(modules, self, params);
    fn_27_2E2754(modules + 0x1634, modules + 0x804, params);
    fn_27_1D90FC(self);

    char* q = lbl_27_data_9132C;
    *(void**)(self + 0x3c) = q;
    *(void**)(self + 0x40) = q + 0x64;
    *(void**)(self + 0x48) = q + 0x70;
    *(void**)(self + 0x54) = q + 0x84;
    *(void**)(self + 0x64) = q + 0xdc;
    *(void**)(self + 0x70) = q + 0xec;
    *(void**)(self + 0x7c) = q + 0x100;
    *(void**)(self + 0x88) = q + 0x118;
    *(void**)(self + 0x90) = q + 0x124;

    cb[0] = 0;
    cb[1] = 0;
    cb[2] = 0;
    Object_vptr_0* callback = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
    callback->slot28(cb, 3);

    fn_27_1D8FC8(self, 0);
    return arg0;
}
