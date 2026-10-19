#pragma force_active on
extern void* lbl_27_bss_120[];

class utArchiveManager {
public:
    void* resolveReference(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
};

extern "C" {
void* fn_27_6FF4C(unsigned int* p, unsigned long q)
{
    return ((utArchiveManager*)lbl_27_bss_120[p[0]])->resolveReference(p[1], q, 0, 0, 0, 0);
}
}
