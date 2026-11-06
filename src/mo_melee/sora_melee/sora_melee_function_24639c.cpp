#pragma force_active on

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual unsigned int slot25();
    virtual unsigned int slot26();
};

extern "C" unsigned int fn_8004E958(void*);
extern "C" bool fn_27_241F14(void*);
extern "C" bool fn_27_241F00(void*);
extern "C" unsigned int fn_27_23AC10(void*);
extern void* g_GameGlobal;
extern void* g_ftManager;

struct Obj {
    char pad[0x41];
    unsigned char unk41;
    char pad2[2];
    void* unk44;
    void* slots[7];
};

extern "C" void fn_27_24639C(Obj* self) {
    if (fn_8004E958(g_GameGlobal) != 0 &&
        !fn_27_241F14(self) &&
        !fn_27_241F00(self) &&
        self->unk41 != 0) {
        int off;
        int i = 0;
        off = 0;
        for (; i < 7; i++, off += 0x5C) {
            if (self->slots[i] != 0 &&
                ((Object_vptr_3c*)self->slots[i])->slot26() != 1U &&
                ((Object_vptr_3c*)self->slots[i])->slot25() != 0 &&
                fn_27_23AC10(self->slots[i]) != 1U) {
                char* base = (char*)self->unk44;
                if (((unsigned int)((base[9] >> 5) & 7) != 1U) || base[off + 0x9C] != 0) {
                    if (*(unsigned char*)((char*)g_ftManager + 0x6B) == 0) {
                        ((Object_vptr_3c*)self->slots[i])->slot23();
                    }
                }
            }
        }
    }
}
