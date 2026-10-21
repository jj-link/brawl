#pragma force_active on
struct PitContext;

class PitModule {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual void setMode(int, PitContext*);
};

struct PitModuleAccesser {
    unsigned char padding[0x70];
    PitModule* module;
};

struct PitContext {
    unsigned char padding[0xD8];
    PitModuleAccesser* accesser;
};

struct PitObject {
    unsigned char padding[0x60];
    PitContext* context;
};

extern "C" int fn_27_1DAF80(void*);

extern "C" int fn_112_10EB8(PitObject* self, int enabled) {
    if (enabled != 0) {
        PitContext* context = self->context;
        context->accesser->module->setMode(4, context);
        return 1;
    } else {
        return fn_27_1DAF80(self);
    }
}
