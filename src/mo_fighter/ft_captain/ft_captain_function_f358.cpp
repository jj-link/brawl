#pragma force_active on
extern "C" void fn_100_10288();
extern "C" void fn_100_1046C();
extern "C" void fn_100_10B74(void* self);
extern "C" void fn_100_FC20(void* self);
extern "C" void fn_100_FCE0();
extern "C" void fn_100_10518(void* self, int x);
extern "C" void fn_100_10774();
extern "C" void fn_100_F7F4();

extern "C" {
void fn_100_F358(void* unused, void* self);
}

extern "C" void fn_100_F358(void* unused, void* self) {
    fn_100_10288();
    fn_100_1046C();
    fn_100_10B74(self);
    fn_100_FC20(self);
    fn_100_FCE0();
    fn_100_10518(self, 0);
    fn_100_10774();
    fn_100_F7F4();
}
