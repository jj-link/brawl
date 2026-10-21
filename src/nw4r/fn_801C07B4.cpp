#pragma force_active on
extern "C" {
extern void fn_8020270C(void* dst, void* src);

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} Vec3Copy;

void fn_801C07B4(unsigned char* arg0, int arg1, Vec3Copy* arg2) {
    Vec3Copy tmp;
    tmp = *arg2;
    fn_8020270C(&tmp, arg0 + 0x30);
}
}
