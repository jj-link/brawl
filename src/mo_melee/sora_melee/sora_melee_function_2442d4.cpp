#pragma force_active on
struct Callback {
    char pad[0x3C];

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
    virtual void invoke();
};

struct Object {
    char pad[0x90];
    Callback* callback;
};

struct GameState {
    char pad[0x1A];
    unsigned short mode;
};

struct GameValue {
    char pad[4];
    float value;
};

struct GameGlobal {
    char pad0[8];
    GameState* state;
    char pad1[0x38];
    GameValue* values;
};

extern "C" {
    extern GameGlobal* g_GameGlobal;
    extern const float lbl_27_rodata_3EE0[];

    void fn_27_2442D4(Object* self) {
        Callback* callback = self->callback;
        if (callback) {
            callback->invoke();
        }

        GameGlobal* global = g_GameGlobal;
        unsigned int mode = global->state->mode;
        if (mode == 5 || mode == 8 || mode == 14) {
            global->values->value = lbl_27_rodata_3EE0[0];
        }
    }
}
