#pragma force_active on
typedef unsigned int u32;

struct V3 { float data[3]; };

extern const float lbl_41_rodata_18;

extern "C" void* getInstance__6emInfoFv();
extern "C" u32 getNodeNum__6emInfoF6emKind(void*, int);
extern "C" V3* fn_41_5AC4(V3*, float, float, float);
extern "C" void fn_41_11B2C(V3*, const void*);
extern "C" void fn_41_4D14(V3*, const V3&, const V3&);

struct Module {
    u32 pad[2];
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
    virtual V3 get(u32, int);
};

struct Access {
    char pad[4];
    Module* module;

    Module* getModule() { return module; }
};

struct Enemy {
    char pad[0xac];
    int kind;
    char pad2[0x104];
    Access* access;
    char pad3[0x313c];
};

extern "C" void fn_41_6C44(V3* result, Enemy* enemy, u32 node) {
    if (node >= getNodeNum__6emInfoF6emKind(
                    getInstance__6emInfoFv(), enemy->kind)) {
        fn_41_5AC4(result, lbl_41_rodata_18,
                  lbl_41_rodata_18, lbl_41_rodata_18);
        return;
    }

    V3 offset;
    fn_41_11B2C(&offset, (char*)enemy + 0x32f4);
    const V3& pos = enemy->access->getModule()->get(node, 0);
    V3 temp;
    fn_41_4D14(&temp, offset, pos);
    *result = temp;
}
