#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_7D10[];
extern "C" void fn_27_1DB0F0(void*, void*, void*, void*, int);

struct LocalVec { float x,y,z; };
struct Info {
    LocalVec a,b,c;
    float angle;
    int flag;
    int side;
    int effect;
    int id;
    int kind;
    float value;
};
class FighterPart {
public:
    virtual void isNull(); virtual void slot1(); virtual void slot2();
    virtual int slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(Info*);
    virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18();
    virtual void slot19();
};
class Work {
public:
    virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
};
class Effect {
public:
    virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual int slot11(int,int,LocalVec*,LocalVec*,int,int,int,float,int);
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
};
struct Modules { char pad[0x64]; Work* work; char p68[0x20]; Effect* effect; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x60]; Access* access; char p64[0x1864]; FighterPart part; };
struct Event { int kind; int unused; LocalVec pos; };

extern "C" void fn_27_38EC98(Self* self, Event* event, void* a, void* b, int kind) {
    const float* c = lbl_27_rodata_7D10;
    if (kind == 3) {
        switch (event->kind) {
        case 0x838:
            self->access->modules->work->slot18(0x12000003);
            return;
        case 0x839: {
            Info info;
            info.flag = 0;
            info.a.x = event->pos.x; info.a.y = event->pos.y; info.a.z = event->pos.z;
            info.b.x = event->pos.x; info.b.y = event->pos.y; info.b.z = event->pos.z;
            info.c.x = c[1]; info.c.y = c[1]; info.c.z = c[1];
            float f = soValueAccesser::getConstantFloat((soModuleAccesser*)self->access, 0xfa7, 0);
            float random = randf();
            random -= c[6];
            info.angle = random * f;
            info.kind = (self->part.slot3() == 0) + 1;
            LocalVec v2;
            LocalVec v1;
            v1.x = c[1]; v1.y = c[1]; v1.z = c[1];
            v2.x = c[1]; v2.y = c[1]; v2.z = c[1];
            info.effect = self->access->modules->effect->slot11(0x1d0006, info.kind, &v2, &v1, 0, 0x20, 0, c[2], -1);
            info.side = self->part.slot3() == 0;
            int result = self->part.slot3();
            int id = 0x456;
            if (result == 0) id = 0x457;
            info.id = id;
            info.value = c[1];
            self->part.slot10(&info);
            self->access->modules->work->slot18(0x12000004);
            return;
        }
        case 0x83a:
            self->access->modules->work->slot19(0x12000005);
            return;
        }
    }
    fn_27_1DB0F0(self, event, a, b, kind);
}
