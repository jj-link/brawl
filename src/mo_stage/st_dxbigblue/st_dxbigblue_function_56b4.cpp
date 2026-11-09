#include <mt/mt_prng.h>
#pragma force_active on
struct StageData { char pad[0xa0]; float min; float max; char pad2[0xc]; float value; };
struct Position { float x, y; };
struct Ref { float x, y; };
struct Object_base { char pad[0x3c]; };
class Object : public Object_base {
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
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual StageData* getStageData();
    char pad[0x164-0x40];
    Ref* ref;
    char pad2[4];
    float value;
    float speed;
    char pad3[4];
    unsigned char flag;
};
extern "C" void fn_81_5130(Object*, void*, void*, int);
extern "C" void fn_801342C8(void*, Position*);
extern "C" void fn_81_56B4(Object* self, void* status, void* unused, int enabled) {
    fn_81_5130(self, status, unused, enabled);
    if (enabled) {
        StageData* data = self->getStageData();
        if (data) {
            Position pos;
            fn_801342C8(status, &pos);
            self->value = data->value;
            if (pos.x > self->ref->y)
                self->flag = 1;
            else
                self->flag = 0;
            self->speed = data->min + (data->max - data->min) * randf();
            if (self->flag == 1)
                self->speed = -self->speed;
        }
    }
}