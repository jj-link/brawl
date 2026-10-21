#pragma force_active on
extern "C" void addTail__6utListFP10utListNode(void*, void*);

struct ShadowObject {
    unsigned char data[0x34];
};

struct Shadow {
    unsigned char pad[0x46];
    unsigned short count;
    unsigned char pad48[0x34];
    unsigned int activeCount;
    ShadowObject* objects;
    unsigned int list84;
    unsigned int list88;
    unsigned int list8C;
    unsigned int list90;
    unsigned int list94;
    unsigned int list98;
};

extern "C" void clearShadowObject__8stShadowFv(Shadow* self) {
    self->list88 = 0;
    self->list84 = 0;
    self->list8C = 0;
    self->list94 = 0;
    self->list90 = 0;
    self->list98 = 0;

    for (unsigned int i = 0; i < self->count; ++i) {
        addTail__6utListFP10utListNode(&self->list90, &self->objects[i]);
    }

    self->activeCount = 0;
}
