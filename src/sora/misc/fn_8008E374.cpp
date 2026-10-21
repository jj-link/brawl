#pragma force_active on
namespace nw4r { namespace g3d { class ScnMdl; } }

extern "C" int fn_8008E4E8(void* a, unsigned long* b, int* c);
void nwSMSetNodeVisibility(nw4r::g3d::ScnMdl* m, long id, const unsigned long* flags, bool enable);

extern "C" void fn_8008E374(void* a, nw4r::g3d::ScnMdl* arg1) {
    unsigned char sp10[0x320];
    int sp8;
    int temp;
    sp8 = *(int*)((char*)arg1 + 0xE8);
    temp = fn_8008E4E8(a, (unsigned long*)sp10, &sp8);
    if (temp != 0) {
        nwSMSetNodeVisibility(arg1, temp, (unsigned long*)sp10, 0);
    }
}
