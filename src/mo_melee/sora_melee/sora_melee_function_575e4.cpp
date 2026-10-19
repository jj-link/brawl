#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Data {
    u8 pad[0x34];
    u32 flags;
};

struct Context {
    u8 pad[0x29];
    u8 state;
};

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void action(int, int, int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int test();
    virtual void update(Data*, float);
};

extern "C" void fn_27_575E4(
    Object* self, Data* data, int, int, int, Context* context, float value
) {
    if (self->test() && ((data->flags >> 25) & 31)) {
        if (context->state == 1) {
            self->action(0xbd, 0, 0, 0);
        } else {
            self->update(data, value);
        }
    }
}
