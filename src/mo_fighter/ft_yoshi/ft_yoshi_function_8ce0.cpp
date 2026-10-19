#pragma force_active on
extern "C" {
void fn_27_CB410(void*, int, int);
void fn_27_B215C(void*, void*, void*, void*, void*, void*);

void* fn_95_8CE0(void* self, void* p1, void* p2, void* p3, void* p4) {
    fn_27_CB410(self, 1, 0);
    fn_27_B215C((char*)self + 0x50, p1, self, p2, p3, p4);
    return self;
}
}
