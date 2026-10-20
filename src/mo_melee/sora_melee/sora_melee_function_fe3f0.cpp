#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} FlagHolder;

void fn_27_FE3F0(FlagHolder* p) {
    p->flags &= 0xFDFFFFFF;
}
}
