#pragma force_active on
struct gfPadStatus;

struct gfPadSystem {
    int getSysPadStatus(int, gfPadStatus *);
};

extern gfPadSystem *g_gfPadSystem;

extern "C" {
int fn_90_1C7C(int port, gfPadStatus *status)
{
    return g_gfPadSystem->getSysPadStatus(port, status);
}
}
