#pragma force_active on
extern "C" {
extern int fn_80163BE4(int, void*);

int fn_80164E3C(void* arg0) {
    return fn_80163BE4(*(int*)((char*)arg0 + 0xbc), arg0);
}
}
