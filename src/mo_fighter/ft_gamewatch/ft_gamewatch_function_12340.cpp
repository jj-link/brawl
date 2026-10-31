#pragma force_active on
struct Ret2 {
    int x;
    int y;
};

struct SituationModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int kind();
};

struct StatusModule {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual int statusCall(int);
};

struct KineticModule {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* energy(int);
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual Ret2 speed(short*);
};

struct WorkModule {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual int workCall(int);
};

struct AbsorberModule {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* absCall(int, int, int);
};

struct Modules {
    char pad0[0x14];
    SituationModule* situation;
    char pad1[0x14];
    AbsorberModule* absorber;
    char pad2[0x34];
    WorkModule* work;
    char pad3[0x08];
    StatusModule* status;
    char pad4[0x08];
    KineticModule* kinetic;
};

struct GameWatch {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern const char lbl_107_data_8CA4[];
extern const char lbl_107_data_3B18[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_107_12340(void*, GameWatch* self) {
    if (self->modules->situation->kind() == 2) {
        if (self->modules->status->statusCall(0) != 0x11a) {
            const float* scale = *reinterpret_cast<const float**>(
                reinterpret_cast<char*>(
                    getData__20ftCommonDataAccesserCF6ftKind(
                        g_ftCommonDataAccesser, 0x12)) + 0x88);

            void* energyObject = self->modules->kinetic->energy(3);
            float* energy = static_cast<float*>(__dynamic_cast(
                energyObject, 0, lbl_107_data_8CA4, lbl_107_data_3B18, 1));

            short flag = 1;
            Ret2 speed;
            Ret2 copiedSpeed;
            speed = self->modules->kinetic->speed(&flag);
            copiedSpeed = speed;
            *reinterpret_cast<float*>(&copiedSpeed.x) =
                *reinterpret_cast<float*>(&copiedSpeed.x) / *scale;
            energy[2] = *reinterpret_cast<float*>(&copiedSpeed.x);
            energy[3] = *reinterpret_cast<float*>(&copiedSpeed.y);
        }
    }

    if (self->modules->work->workCall(0x22000013) != 0) {
        self->modules->absorber->absCall(0, 1, 0);
    }
}
