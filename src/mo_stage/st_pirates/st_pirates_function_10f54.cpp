#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Class_1A68 {
public:
    virtual void fn_52_8E6C();
    virtual void fn_52_828C();
    virtual void fn_52_829C();
    virtual void fn_52_75D0();
    virtual void fn_52_7344(int, int);
    Flags* data;
    u32 state;
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void processPreMapCorrection(); virtual void slot5(); virtual void processFixPosition(); virtual void processPreCollision();
    virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
    virtual void slot12(); virtual void processEffect(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(int); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67();
    virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
    virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
    virtual void slot76(); virtual void slot77(); virtual void slot78(const char*);
};
struct Obj {
    Obj(const char*);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x84];
    u32 f160;
    float f164, f168, f16c;
    u32 f170, f174;
};
namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" void fn_52_35D0(void*, const char*);
extern char lbl_52_data_37B8[];
extern const float lbl_52_rodata_2E8;
inline Obj::Obj(const char* name) {
    fn_52_35D0(this, name);
    vtable = lbl_52_data_37B8;
    f160 = 0;
    f164 = lbl_52_rodata_2E8;
    f168 = lbl_52_rodata_2E8;
    f16c = lbl_52_rodata_2E8;
    f170 = 0;
    f174 = 0;
    Class_1A68* p = (Class_1A68*)part;
    if (!p) return;
    p->state = 1;
    p->fn_52_7344(0, 15);
    p->data->flags |= 1;
}
extern "C" Obj* fn_52_10F54(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((Object_vptr_3c*)obj)->slot42(arg0);
        ((Object_vptr_3c*)obj)->slot78(arg1);
    }
    return obj;
}