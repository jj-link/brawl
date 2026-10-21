#pragma force_active on

extern "C" void changeMsgBuf__7MessageFi(void* self, int index);
extern "C" void fn_8006A750(void* arg0, void** arg1);

extern "C" void fn_800B955C(void* arg0, int arg1, int arg2) {
    changeMsgBuf__7MessageFi(*(void**)((char*)arg0 + 8), arg1);
    fn_8006A750(*(void**)((char*)arg0 + 8), (void**)arg2);
}
