#pragma force_active on
class SceneResource {
public:
    virtual ~SceneResource();
};

struct Scene {
    unsigned char pad[12];
    void* task;
};

extern "C" {
extern SceneResource* lbl_1_bss_60;
extern void* lbl_8049DEC8;

void fn_20_9044(void*);
void exit__6gfTaskFv(void*);
void fn_8009A540(void*);
void fn_8009A2A8(void*);

int fn_1_CB20(Scene* self) {
    if (lbl_1_bss_60) {
        delete lbl_1_bss_60;
    }

    fn_20_9044(self->task);
    exit__6gfTaskFv(self->task);

    if (lbl_8049DEC8) {
        fn_8009A540(lbl_8049DEC8);
        fn_8009A2A8(lbl_8049DEC8);
    }

    return 0;
}
}
