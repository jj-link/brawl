#pragma force_active on
class Class_6528 {
public:
    virtual void fn_119_58E4();
    virtual void fn_119_1164C();
    virtual void fn_119_13428();
    virtual void fn_119_13424();
    virtual void fn_119_13420();
    virtual void fn_119_1341C();
    virtual void fn_119_13414();
    virtual void fn_119_1345C();
    virtual void fn_119_13454();
    virtual void fn_119_1344C();
    virtual void fn_119_13444();
    virtual void fn_119_1343C();
    virtual float getFloat(unsigned long);
    virtual void fn_119_13408();
    virtual void fn_119_133FC();
    virtual void fn_119_133F4();
    virtual void fn_119_133E8();
};
class Class_6700 {
public:
    virtual void fn_119_58E4();
    virtual void fn_119_11708();
    virtual void fn_119_13614();
    virtual void fn_119_1360C(int, void*);
    virtual void fn_119_13604();
    virtual void fn_119_135FC();
    virtual void fn_119_135F4();
    virtual void fn_119_135EC();
    virtual void fn_119_135E4();
    virtual void fn_119_135DC();
    virtual void fn_119_135D4();
    virtual void fn_119_135CC();
    virtual void fn_119_135C4();
    virtual void fn_119_135BC();
    virtual void fn_119_1356C();
    virtual void fn_119_135B4();
    virtual int getStatusKind();
};
struct Event {
    int kind;
    unsigned char pad04[0x10];
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
};
struct Inner {
    unsigned char pad00[0x64];
    Class_6528* model;
    unsigned char pad68[8];
    Class_6700* status;
};
struct SoValueAccesser {
    unsigned char pad00[0xD8];
    Inner* inner;
};
struct Self {
    unsigned char pad00[0x60];
    void* p60;
};
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    SoValueAccesser*, unsigned long, unsigned long);
extern "C" void fn_27_1324D4(
    Self*, Event*, SoValueAccesser*, void*, int);
extern "C" void fn_119_8A28(
    Self* self,
    Event* event,
    SoValueAccesser* accesser,
    void* arg3,
    int arg4)
{
    Class_6700* status = accesser->inner->status;

    switch (event->kind) {
    case 0x27:
        if (status->getStatusKind() == 0x116 ||
            status->getStatusKind() == 0x122 ||
            status->getStatusKind() == 0x123 ||
            status->getStatusKind() == 0x124) {
            unsigned long base = 0x21000000;

            event->f1C = accesser->inner->model->getFloat(base + 0xC);
            event->f20 = accesser->inner->model->getFloat(base + 0xD);
            event->f24 = accesser->inner->model->getFloat(base + 0xE);
            event->f18 = (float)getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0x5DC9, 0);
            event->f14 = accesser->inner->model->getFloat(base + 0x10);
        }
        break;

    case 0x29:
        if (status->getStatusKind() == 0x125) {
            status->fn_119_1360C(0x126, self->p60);
        }
        break;
    }

    fn_27_1324D4(self, event, accesser, arg3, arg4);
}
