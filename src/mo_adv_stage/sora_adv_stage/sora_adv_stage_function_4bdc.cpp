#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

enum SndID { SND_ID_DUMMY = 0 };
enum EfID { EF_ID_DUMMY = 0 };

class sndSystem {
public:
    void playSE(SndID id, int a, int b, int c, int d);
};

class ecMgr {
public:
    int setEffect(EfID id, Vec3f* pos);
};

extern sndSystem* g_sndSystem;
extern ecMgr* g_ecMgr;

extern "C" int fn_40_4C48(int a, char* b, Vec3f* out);

extern "C" void fn_40_4BDC(int a, char* b) {
    Vec3f pos;
    if (fn_40_4C48(a, b, &pos)) {
        g_sndSystem->playSE((SndID)*(int*)(b + 0x24), -1, 0, 0, -1);
        g_ecMgr->setEffect((EfID)*(int*)(b + 0x28), &pos);
    }
}
