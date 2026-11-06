#pragma force_active on

typedef unsigned char u8;

struct Data {
    u8 a;
    u8 b;
};

struct Object_vptr_3c_base { char pad[0x3c]; };

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual Data* slot37();
};

struct Mgr { Object_vptr_3c* o[7]; };

struct Self {
    char pad0[0x140];
    int v140[7];
    char pad1[0x1b8 - 0x15c];
    int start;
    int lim;
    int cur;
    char pad2[0x1e1 - 0x1c4];
    u8 flag;
    char pad3[0x1ec - 0x1e2];
    int cnt[7];
};

extern Mgr* g_stLoaderManager;

extern "C" int fn_27_24CC58(Self* self, unsigned int arg1, int arg2, Object_vptr_3c** outObj, int* outIdx, u8* outFlag) {
    int i;
    Object_vptr_3c* obj;
    if (self->flag != 0) {
        *outObj = 0;
        if (arg1 < 0x2e) {
            i = self->cur - 1;
        } else {
            i = self->lim - 1;
        }
        while (i >= self->start) {
            if (self->v140[i] < self->cnt[i]) {
                obj = g_stLoaderManager->o[i];
                if (obj != 0) {
                    Data* d = obj->slot37();
                    if ((d->a >= 0x2e && d->a <= 0x31) || d->b == 3) {
                        *outObj = obj;
                        *outIdx = i;
                        *outFlag = 1;
                        return 1;
                    }
                }
            }
            i--;
        }
    } else {
        *outObj = 0;
        for (i = self->start; i < self->lim; i++) {
            if (self->v140[i] < self->cnt[i]) {
                obj = g_stLoaderManager->o[i];
                if (obj != 0) {
                    *outObj = obj;
                    *outIdx = i;
                    *outFlag = 1;
                    return 1;
                }
            }
        }
    }
    return *outObj != 0;
}
