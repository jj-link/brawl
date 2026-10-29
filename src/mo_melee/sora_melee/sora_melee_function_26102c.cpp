#pragma force_active on

typedef unsigned long u32;

struct ResMdl {
    void* data;
};

struct ScnMdl {
    char pad[0xE8];
    void* resource;
};

struct CopiedVisAccess {
    ScnMdl* model;
    u32 node;
    unsigned char* visibility;
};

struct ResNodeData {
    char pad[0x14];
    u32 flags;
    char pad18[0x48];
    int offset1;
    int offset2;
};

class GroundBase {
public:
    char pad0[0x3C];
};

class Ground : public GroundBase {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual bool setNodeVisibility(bool, u32, u32, bool, bool);

    char pad40[4];
    ScnMdl** models;
    char pad48[0x25];
    unsigned char unk6D;
    char pad6E[6];
    void* unk74[9];
};

extern "C" ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const ResMdl*, u32);
extern "C" void __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
    CopiedVisAccess*, ScnMdl*, u32);
extern "C" void SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
    CopiedVisAccess*, bool);

extern "C" bool setNodeVisibility__6GroundFbUlUlbb(
    Ground* self, bool arg0, u32 arg1, u32 arg2, bool arg3, bool arg4)
{
    ResMdl mdl;
    mdl.data = 0;
    ScnMdl* model = self->models[arg1];
    if (!model) return false;

    mdl.data = model->resource;
    if (!mdl.data) return false;

    ResNodeData* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&mdl, arg2);
    if (!node) return false;

    if (arg3 == 1) {
        int offset = node->offset1;
        void* p = offset ? (char*)node + offset : 0;
        if (p) {
            u32 val = p ? *(u32*)((char*)p + 0xC) : 0;
            self->setNodeVisibility(arg0, arg1, val, arg3, true);
        }
    }

    if (arg4 == 1) {
        int offset = node->offset2;
        void* p = offset ? (char*)node + offset : 0;
        if (p) {
            u32 val = p ? *(u32*)((char*)p + 0xC) : 0;
            self->setNodeVisibility(arg0, arg1, val, arg3, arg4);
        }
    }

    unsigned int flag = self->unk6D;
    if ((flag >> 7) & 1) {
        CopiedVisAccess access;
        __ct__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFPQ34nw4r3g3d6ScnMdlUl(
            &access, model, arg2);
        SetVisibility__Q44nw4r3g3d6ScnMdl15CopiedVisAccessFb(
            &access, arg0);
    }

    if (node) {
        if (arg0)
            node->flags |= 0x100;
        else
            node->flags &= ~0x100;
    }

    return true;
}
