#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

typedef unsigned long uint;

struct Data {
    char pad[0x40];
    char values[0x24];
    uint offset;
};

struct Matrix {
    uint data[12];
};

struct Obj {
    char pad[0xe8];
    Data* data;
    Matrix* buffer;
    uint* fieldF0;
    char padF4[0x10];
    uint flags;
    uint field108;
    int count;
};

extern "C" {
uint fn_8015D804(void*);
void fn_801D76BC(void*, uint);
void fn_801A5414(void*, uint*, nw4r::g3d::ResMdl*, int);
void fn_8015D8C0(void*, void*, uint);
void fn_8015D874();

void fn_8004765C(Obj* self, Obj* other, uint* indices, int length) {
    Data* data = self->data;
    nw4r::g3d::ResMdl model(data);
    char* base = data->values;
    uint count = *(uint*)(base + data->offset);
    uint* flags;
    Matrix* buffer;
    uint enabled = 0;

    if (count > 8 && count < 0x156 &&
        (enabled = fn_8015D804(base)) == 1) {
        fn_801D76BC(self->buffer, count * 0x30);
        buffer = (Matrix*)0xe0000000;
    } else {
        buffer = self->buffer;
        self->flags &= ~1U;
    }

    flags = self->fieldF0;
    nw4r::g3d::ResMdl otherModel(other->data);
    Matrix* otherBuffer = other->buffer;
    uint* otherFlags = other->fieldF0;

    int i = 0;
    for (; i < length; indices++, i++) {
        nw4r::g3d::ResNode node = model.GetResNode(i);
        uint dst = node.IsValid() ? *(uint*)((char*)node.ptr() + 0x10) : 0;
        nw4r::g3d::ResNode otherNode = otherModel.GetResNode(*indices);
        uint src = otherNode.IsValid()
                       ? *(uint*)((char*)otherNode.ptr() + 0x10)
                       : 0;
        Matrix* source = &otherBuffer[src];
        buffer[dst] = *source;
        flags[dst] = otherFlags[src];
    }

    int items = self->count;
    if (items) {
        nw4r::g3d::ResMdl local(model);
        fn_801A5414(buffer, flags, &local, items);
    }

    if (enabled) {
        fn_8015D8C0(self->buffer, (void*)0xe0000000, count * 0x30);
        fn_8015D874();
    }
}
}
