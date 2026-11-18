#include <gf/gf_task_scheduler.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern const float lbl_27_rodata_7D68[];

struct Command {
    virtual void v0();
    virtual signed char group();
    virtual signed char type();
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3f position();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float direction();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned long getInt(unsigned long);
    virtual void setInt(int, unsigned long, void*);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
};

struct Effect {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual unsigned long create(unsigned long, Vec3f*, const Vec3f&, int, int, float);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void createOnNode(unsigned long, int, const Vec3f&, const Vec3f&, int, int, int, int, float);
};

struct SoundArg {
    int id;
    bool flag;
    Vec3f position;

    SoundArg(const Vec3f& p) : id(0x458), flag(false), position(p) {}
};

struct Sound {
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
    virtual void v13();
    virtual void v14();
    virtual void play(int, SoundArg*);
};

struct AttackData {
    char prefix[0x24];
    Vec3f scale;
    unsigned int slot : 9;
    unsigned int rest30 : 23;
    unsigned int other;
    unsigned int rest38 : 27;
    unsigned int low : 5;
} __attribute__((aligned(8)));

struct Collision {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void set(int, int, AttackData*);
};

struct ModelPrefix {
    char pad[8];
};

struct Model : ModelPrefix {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual Vec3f transform(int, Vec3f*, int, int);
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75();
    virtual bool hidden();
};

struct Modules {
    char pad0[4];
    Model* model;
    char pad8[4];
    Posture* posture;
    char pad10[0xc];
    Collision* collision;
    char pad20[0x34];
    Sound* sound;
    char pad58[0xc];
    Work* work;
    char pad68[0x20];
    Effect* effect;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Entry {
    unsigned long effect;
    float timer;
    Vec3f position;
    int collision;
    unsigned int kind;
};

struct ObjectPrefix {
    char pad[0x3c];
};

struct Object : ObjectPrefix {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46();
    virtual int valid(signed char);

    char pad40[0x20];
    Access* access;
    char pad64[0x1fb8];
    Entry entries[3];

    unsigned int findSlot(int id) {
        if (id == entries[0].collision)
            return 0;
        if (id == entries[1].collision)
            return 1;
        if (id == entries[2].collision)
            return 2;
        return 3;
    }
};

extern "C" int fn_27_1DA24C(Object*, Command*, Access*, int);
extern "C" void fn_27_41310(signed char*, Command*, AttackData*, int*, int*,
                            Access*);

extern "C" int fn_27_395028(Object* self, Command* cmd, Access* access, int arg) {
    const float* rodata = lbl_27_rodata_7D68;

    if (!self->valid(cmd->group()))
        return 0;

    if (cmd->type() <= 10 || cmd->type() >= 16)
        return fn_27_1DA24C(self, cmd, access, arg);

    switch (cmd->type()) {
    case 11: {
        SoundArg sound(Vec3f(rodata[2], rodata[2], rodata[2]));
        sound.position = access->modules->posture->position();
        access->modules->sound->play(3, &sound);
        return 1;
    }
    case 14: {
        unsigned long id = self->access->modules->work->getInt(0x1000000b);
        if (id != 0) {
            gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
                (gfTask::Category)0x12, id);
            if (task != 0)
                task->exit();
            self->access->modules->work->setInt(0, 0x1000000b, self->access);
        }
        return 1;
    }
    case 12:
        for (int i = 0; i < 3; ++i) {
            if (self->entries[i].effect == 0) {
                float direction = access->modules->posture->direction();
                float z = access->modules->work->getFloat(0x11000003);
                float y = access->modules->work->getFloat(0x11000002);
                Vec3f offset(rodata[2], y, z);
                Vec3f position = access->modules->model->transform(0, &offset, 0, 0);
                float angle;
                if (direction > rodata[2])
                    angle = access->modules->work->getFloat(0x11000001);
                else
                    angle = access->modules->work->getFloat(0x11000001) - rodata[4];
                self->entries[i].effect = access->modules->effect->create(
                    0xfa0014, &position, Vec3f(rodata[2], angle, rodata[2]), 0, -1, rodata[0]);
                self->entries[i].position = position;
                self->entries[i].timer = rodata[2];
                break;
            }
        }
        return 1;
    case 13: {
        AttackData data;
        ((float*)&data.scale)[0] = rodata[0];
        ((float*)&data.scale)[1] = rodata[0];
        ((float*)&data.scale)[2] = rodata[0];
        data.low = 0;
        int a = -1;
        int b = -1;
        signed char flag = 0;
        fn_27_41310(&flag, cmd, &data, &a, &b, access);
        for (int i = 0; i < 3; ++i) {
            if (self->entries[i].effect != 0 && self->entries[i].collision == 0) {
                int id = 4;
                for (int j = 0; j < 3; ++j) {
                    unsigned int k;
                    for (k = 0; k < 3; ++k)
                        if (id == self->entries[k].collision)
                            break;
                    if (k == 3)
                        break;
                    ++id;
                }
                self->entries[i].collision = id;
                self->entries[i].kind = data.slot = id - 3;
                access->modules->collision->set(id, id, &data);
                break;
            }
        }
        return 1;
    }
    case 15:
        if (!access->modules->model->hidden()) {
            access->modules->effect->createOnNode(
                0x1e0001, 0x2a, Vec3f(rodata[2], rodata[2], rodata[2]),
                Vec3f(rodata[2], rodata[2], rodata[2]), 1, 0, 0, -1, rodata[0]);
        }
        return 1;
    default:
        return 0;
    }
}
