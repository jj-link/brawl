#pragma force_active on

struct Command {
    int type;
    int pad;
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
    Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}
};

class Position {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 get();
    virtual void set(const Vec3&);
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setOffset(unsigned int, float);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void setObject(unsigned int);
    virtual void sendMessage(unsigned int);
};

class Status {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void change(unsigned int, void*);
};

struct Modules {
    char pad[0xC];
    Position* position;
    char pad2[0x54];
    Work* work;
    char pad3[8];
    Status* status;
};

struct Context {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_174B48(void*, Command*, Context*);

extern "C" void fn_27_178698(void* self, Command* cmd, Context* context) {
    int type = cmd->type;

    if (type <= 0x1B || type >= 0x22) {
        fn_27_174B48(self, cmd, context);
        return;
    }

    switch (type) {
    case 0x1F:
        context->modules->work->setObject(0x22000010);
        break;

    case 0x20: {
        Vec3 position = context->modules->position->get();
        context->modules->work->setOffset(0x21000004, cmd->x - position.x);
        context->modules->work->setOffset(0x21000005, cmd->y - position.y);
        position.x = cmd->x;
        position.y = cmd->y;
        context->modules->position->set(position);
        break;
    }

    case 0x21:
        context->modules->work->sendMessage(0x22000010);
        context->modules->status->change(0x49, context);
        break;
    }
}
