#pragma force_active on
struct ResFile {
    void* data;
};

struct Obj {
    char padding[0x94];
    void* field;
};

extern "C" {
void Init__Q34nw4r3g3d7ResFileFPv(ResFile*);
int fn_8018E374(ResFile*);
void* fn_8018D4D0(ResFile*, void*);

int fn_27_222990(Obj* self, void* data, void* name) {
    ResFile file;
    int result = 0;

    file.data = data;
    Init__Q34nw4r3g3d7ResFileFPv(&file);
    if (file.data != 0) {
        if (fn_8018E374(&file) != 0) {
            self->field = fn_8018D4D0(&file, name);
            result = 1;
        }
    }
    return result;
}
}
