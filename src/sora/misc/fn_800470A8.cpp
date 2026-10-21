#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Vec {
    float x, y, z;
};

struct Matrix {
    float m[3][4];
};

struct ResNodeData {
    char pad[0x10];
    u32 id;
};

extern "C" {
extern char lbl_8042B6B8[];
extern const float lbl_805A17E8;

u8* fn_8018ECCC(const void*, const char*);
ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const void*, u32);
void fn_801628B4(Matrix*, const Matrix*, const Vec*);

void fn_800470A8(Matrix* matrices, const u8* commands,
                 const void* model, const Vec* vectors) {
    if (!commands) {
        commands = fn_8018ECCC(model, lbl_8042B6B8);
        if (!commands)
            return;
    }

    const float zero = lbl_805A17E8;
    while (*commands != 1) {
        if (*commands == 2) {
            u32 index = (commands[1] << 8) + commands[2];
            if (zero != vectors[index].x ||
                zero != vectors[index].y ||
                zero != vectors[index].z) {
                ResNodeData* node =
                    GetResNode__Q34nw4r3g3d6ResMdlCFUl(model, index);
                u32 id = node ? node->id : 0;
                Matrix* matrix = &matrices[id];
                fn_801628B4(matrix, matrix, &vectors[index]);
            }
        }
        commands += 5;
    }
}
}
