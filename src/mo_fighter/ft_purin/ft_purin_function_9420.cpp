#pragma force_active on
extern "C" void* fn_124_950C(char*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_124_9420(void* p)
{
    int i = 0;
    while (i < 1) {
        void* q = fn_124_950C(reinterpret_cast<char*>(p) + 0xc, i);
        if (fn_27_8D3E4(reinterpret_cast<char*>(q) + 0x88) == 0) break;
        ++i;
    }
}
