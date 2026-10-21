#pragma force_active on
class gfSceneRoot;

extern "C" void fn_27_25F8B8(void*, void*, int);
extern "C" void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
extern gfSceneRoot* g_gfSceneRoot;

struct Flags6C {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char rest : 6;
};

struct GroundBase {
    char pad0[0x3C];

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
    virtual void visibility(unsigned long);
};

struct Ground : GroundBase {
    char pad40[4];
    void** unk44;
    char pad48[0x10];
    unsigned int unk58;
    char pad5C[0x10];
    Flags6C unk6C;

    void setVisibilityByClipping(unsigned long arg);
};

void Ground::setVisibilityByClipping(unsigned long arg)
{
    unsigned int count = unk58;
    for (unsigned int i = 0; i < count; i++) {
        if (arg != 0 && !unk6C.b1) {
            fn_27_25F8B8(this, unk44[i], 0);
            visibility(unk6C.b0);
        } else if (arg == 0 && unk6C.b1) {
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(
                g_gfSceneRoot, unk44[i]);
        }
    }
    unk6C.b1 = arg;
}
