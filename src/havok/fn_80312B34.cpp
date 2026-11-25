#pragma force_active on
#pragma fp_contract on

struct Buffer {
    int* data;
    int count;
    unsigned int capacity;
};

struct MeshData {
    char pad[0x0C];
    int value;
};

struct Group {
    unsigned short* entries;
    int count;
    char pad[4];
};

struct Container {
    char pad[0x60];
    float scale[4];
    MeshData* data;
    char pad2[8];
    Group groups[3];
};

extern double lbl_805A4640;

extern "C" {
int fn_80282148(float);
void fn_8027CE3C(void*, int);
}

inline int getCap(Buffer* b) { return b->capacity & 0x3FFFFFFF; }

inline void appendValue(Container* self, unsigned short idx, Buffer* buffer) {
    MeshData* item = &self->data[idx];
    if (buffer->count == getCap(buffer))
        fn_8027CE3C(buffer, 4);
    buffer->data[buffer->count++] = item->value;
}

extern "C" void fn_80312B34(
    Container* self,
    const float* input,
    float* output,
    Buffer* buffer
) {
    unsigned short* entry;
    int outer;
    float coords[4] __attribute__((aligned(16)));
    int ids[3] __attribute__((aligned(16)));
    int i;
    double base = lbl_805A4640;

    coords[0] = input[0];
    coords[1] = input[1];
    coords[2] = input[2];
    coords[3] = input[3];

    i = 0;
    for (; i < 3; ++i) {
        int id = fn_80282148(coords[i] * self->scale[i]) & ~1;
        ids[i] = id;
        coords[i] = (float)id / self->scale[i];
    }

    output[0] = coords[0];
    output[1] = coords[1];
    output[2] = coords[2];
    output[3] = coords[3];

    for (outer = 0; outer < 3; ++outer) {
        Group* group = &self->groups[outer];
        int id = ids[outer];
        int inner = 1;

        while (inner < group->count - 1) {
            entry = (unsigned short*)((char*)group->entries + inner * 4);
            int value = entry[0];

            if (value > 1 && value < 0xFFFC) {
                int adjusted = (int)value + id;

                if (adjusted < 0) {
                    adjusted = value & 1;
                    appendValue(self, entry[1], buffer);
                } else if (adjusted >= 0xFFFC) {
                    adjusted = (value & 1) | 0xFFFC;
                    appendValue(self, entry[1], buffer);
                }

                entry[0] = (unsigned short)adjusted;
            }

            ++inner;
        }
    }
}
