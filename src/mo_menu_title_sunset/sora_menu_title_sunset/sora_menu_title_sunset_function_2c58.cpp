#include <mu/mu_object.h>
#pragma force_active on

extern "C" char lbl_25_data_298[];

struct Title {
    char pad[0x48];
    nw4r::g3d::ResFile res;
    MuObject* first;
    MuObject* second;
    MuObject* third;
    MuObject* objects[35];
    MuObject* main;
    MuObject* cliff;
    MuObject* x1;
    MuObject* back;
    MuObject* others[35];
    char pad2[0xb8c - 0x180];
    char names[35][32];
    char names2[35][32];
};

extern "C" void fn_25_2C58(Title* self, nw4r::g3d::ResFile* file) {
    char (*name)[32];
    const char* base = lbl_25_data_298;
    self->res = *file;
    nw4r::g3d::ResFile::Init(&self->res);
    self->first = MuObject::create(&self->res, base + 0x758, 1, 0, (HeapType)42);
    self->first->changeTexSrtAnimN(base + 0x774);
    self->second = MuObject::create(&self->res, base + 0x788, 1, 0, (HeapType)42);
    self->third = MuObject::create(&self->res, base + 0x794, 1, 0, (HeapType)42);
    name = self->names;
    Title* p = self;
    for (int i = 0; i < 35; i++, name++, p = (Title*)((char*)p + 4)) {
        p->objects[0] = MuObject::create(&self->res, *name, 1, 0, (HeapType)42);
    }
    self->main = MuObject::create(&self->res, base + 0x774, 1, 0, (HeapType)42);
    self->main->changeNodeAnimN(base + 0x774);
    self->main->changeTexSrtAnimN(base + 0x774);
    self->cliff = MuObject::create(&self->res, base + 0x7a4, 1, 0, (HeapType)42);
    self->x1 = MuObject::create(&self->res, base + 0x7ac, 1, 0, (HeapType)42);
    self->x1->changeNodeAnimN(base + 0x7ac);
    self->x1->changeClrAnimN(base + 0x7ac);
    self->x1->changeTexSrtAnimN(base + 0x7ac);
    self->back = MuObject::create(&self->res, base + 0x7b0, 1, 0, (HeapType)42);
    for (int i = 0; i < 35; i++) {
        self->others[i] = MuObject::create(&self->res, self->names2[i], 1, 0, (HeapType)42);
    }
}