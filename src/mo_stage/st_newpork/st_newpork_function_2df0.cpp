#pragma force_active on
class grGimmick {
public:
    void startGimmickSE(unsigned long flag);
};

extern "C" int randi__Fl(long);

extern "C" void fn_69_2DF0(grGimmick* self) {
    unsigned long flag = randi__Fl(0xFF) & 1;
    self->startGimmickSE(flag);
}
