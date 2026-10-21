#pragma force_active on

struct Object;

struct Event {
    Object* object;
    void* value;
    bool found;
};

struct Listener {
    virtual void unused();
    virtual void notify(Event*);
};

struct Object {
    char pad0[0x58];
    Listener** listeners;
    int listenerCount;
    char pad60[0x30];
    void** values;
    int valueCount;

    int find(void* const& value) {
        for (int i = 0; i < valueCount; ++i) {
            if (values[i] == value)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_802E8188(Object* self, void* value) {
    int index = self->find(value);

    Event event;
    event.value = value;
    event.object = self;
    event.found = index >= 0;

    int i = self->listenerCount - 1;
    int offset = i * 4;
    for (; i >= 0; offset -= 4, --i) {
        Listener* listener = *(Listener**)((char*)self->listeners + offset);
        if (listener)
            listener->notify(&event);
    }

    if (index >= 0) {
        self->values[index] = self->values[--self->valueCount];
    }
}
