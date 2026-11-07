#pragma force_active on
extern "C" {
extern void* g_ftManager;
extern char* g_IfMngr;
extern const float lbl_27_rodata_45F0[];
int getPlayerNo__9ftManagerFi(void*, int);
void fn_800E14A4(void*, int, int);
void fn_800E3684(char*, int);
void* fn_80158638();
void fn_80158738(void*, int, int);
}

class Object_vptr_3c_base { public: char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual int slot26();
};

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual int slot43();

    char pad4[0x8];
    unsigned char* unkC;
    char pad10[0x1c];
    char* unk2C;
    Object_vptr_3c* unk30;
    unsigned char unk34;
};

extern "C" void fn_27_27D318(Object_vptr_0* self, int entry, int value, float* pos) {
    const float* data = lbl_27_rodata_45F0;
    int playerNo = getPlayerNo__9ftManagerFi(g_ftManager, entry);
    if (self->unk2C != 0) {
        *(int*)(self->unk2C + playerNo * 4 + 0xd0) = value;
    }
    if (self->slot43() == 0) return;
    if ((self->unkC[0xb] >> 1) & 1) return;
    if (!((self->unk34 >> 5) & 1)) return;
    if (self->unk30 != 0 && self->unk30->slot26() != 0) return;
    if (value != 0) {
        char* m = g_IfMngr;
        fn_800E14A4(*(void**)(m + (unsigned char)(m + (self->unkC + playerNo * 0x5c)[0x9a])[0x68] * 4 + 0x4c), value, 0);
        float v = pos[1];
        float s;
        float hi = data[1];
        float lo = data[0];
        s = data[2];
        float r;
        if (v >= lo && v <= hi) {
            r = s * ((v - lo) / (hi - lo));
        } else if (v < lo) {
            r = data[3];
        } else {
            r = data[4];
        }
        m = g_IfMngr;
        char* obj = *(char**)(m + (unsigned char)(m + (self->unkC + playerNo * 0x5c)[0x9a])[0x68] * 4 + 0x4c);
        if (*(unsigned int*)(obj + 0x1c) == *(unsigned int*)(obj + 0x18)) {
            *(float*)(obj + 0x264) = r;
            fn_800E3684(obj, 1);
        }
    }
    void* o = fn_80158638();
    if (o != 0) {
        fn_80158738(o, playerNo, value);
    }
}
