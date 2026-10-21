#pragma force_active on
extern "C" void fn_8018E808(void*);
extern "C" void exit__6gfTaskFv(void*);

class MenuObject {
    unsigned char padding[0x5C];

public:
    virtual ~MenuObject();
};

struct TitleMenu {
    unsigned char padding[0x1C4];
    void* task;
    MenuObject* first;
    MenuObject* second;
};

extern "C" void fn_24_438(TitleMenu* self) {
    fn_8018E808(reinterpret_cast<unsigned char*>(self) + 0x40);
    exit__6gfTaskFv(self->task);
    self->task = 0;
    delete self->first;
    self->first = 0;
    delete self->second;
    self->second = 0;
}
