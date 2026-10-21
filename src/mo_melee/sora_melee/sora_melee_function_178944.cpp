#pragma force_active on

struct Command {
    int type;
    int pad;
    float x;
    float y;
};

struct Vec3 {
    float x, y, z;

    Vec3(const Vec3& other)
        : x(other.x), y(other.y), z(other.z) {}
};

class Position {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 get();
    virtual void set(const Vec3&);
};

struct Modules {
    char pad[0xC];
    Position* position;
};

struct Context {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_174B48(void*, Command*, Context*);

extern "C" void fn_27_178944(void* self, Command* cmd, Context* context) {
    int type = cmd->type;
    if (type <= 0x26 || type >= 0x29) {
        fn_27_174B48(self, cmd, context);
    } else {
        switch (type) {
        case 0x28: {
            Vec3 v = context->modules->position->get();
            v.x = cmd->x;
            v.y = cmd->y;
            context->modules->position->set(v);
            break;
        }
        }
    }
}
