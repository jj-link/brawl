#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

struct FnSelf {
    char pad[8];
    void* field8;
};

extern "C" int fn_1_93DC(FnSelf* self) {
    exit__6gfTaskFv(self->field8);
    self->field8 = 0;
    return 0;
}
