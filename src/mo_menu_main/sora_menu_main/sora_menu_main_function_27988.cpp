#pragma force_active on
#include <mu/mu_object.h>

class Inner {
public:
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
    virtual void invoke(void*);
};

struct Objects {
    char pad[0x230];
    MuObject* first;
    MuObject* second;
};
struct Resources {
    char pad[0x38];
    void* first;
    void* second;
};
struct Info {
    char pad[0x8c];
    unsigned char count;
};
struct Self {
    char pad[0x64c];
    Objects* objects;
    Resources* resources;
    Inner* inner;
    char pad658[0x18];
    int state;
    int unk674;
    Info* info;
    unsigned char field67c;
    unsigned char field67d;
};

extern "C" {
extern const unsigned char lbl_2_rodata_E70[];
extern char lbl_2_data_3098[];
void fn_800B330C(MuObject*, void*, int);

void fn_2_27988(Self* self, int arg) {
    int state;
    switch (arg) {
    case 0: state = 3; break;
    case 1: state = 5; break;
    case 2: state = 3; break;
    }
    if (state != self->state) {
        self->state = state;
        if (state == 0) {
            self->inner->invoke(self->resources->first);
            self->inner->invoke(self->resources->second);
            return;
        }
        if (state == 1) {
            unsigned char pos = self->field67d;
            int flags = 0;
            if (pos != 0) flags |= 2;
            if (pos + 6 < self->info->count) flags |= 1;
            self->objects->first->setFrameVisible((float)flags);
            unsigned char pos2 = self->field67c;
            int flags2 = 0;
            if (pos2 != 0) flags2 |= 1;
            if (pos2 + 5 < self->info->count) flags2 |= 2;
            self->objects->second->setFrameVisible((float)flags2);
        }
        void* data = lbl_2_data_3098 + lbl_2_rodata_E70[state] * 0x14;
        fn_800B330C(self->objects->first, data, 0);
        fn_800B330C(self->objects->second, data, 0);
    }
}
}
