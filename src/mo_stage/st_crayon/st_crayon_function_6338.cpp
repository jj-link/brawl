#pragma force_active on
typedef struct Fn56Obj {
    int unk0;
    int unk4;
    unsigned int flag : 2;
    unsigned int rest : 30;
} Fn56Obj;

extern "C" void fn_56_6338(Fn56Obj* obj, unsigned int value) {
    obj->flag = value;
}
