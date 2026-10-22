#pragma force_active on
#include <math.h>
struct ftManager;
struct gfTask { char pad[0x28]; int taskId; };
struct Cs { char pad[0x10]; int taskId; };
struct Info { char pad[0xC]; float a; float b; char pad2[0x10]; unsigned char c; };
struct G { char pad[0x14C]; unsigned char f14C; char p; unsigned char f14E; char q; float f150; float f154; Info* f158; };
extern "C" {
extern ftManager* g_ftManager;
extern char lbl_40_data_11D90[];
extern float lbl_40_rodata_728;
bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(void*, void*, int);
gfTask* getTask__6gfTaskFi(int);
int getEntryIdFromTaskId__9ftManagerFiPi(ftManager*, int, int*);
int getPlayerNo__9ftManagerFi(ftManager*, int);
float mtSqrtf__Ff(float);
void fn_40_375F8(G* g, Cs* cs, int unused, int flag);
}
void fn_40_375F8(G* g, Cs* cs, int unused, int flag) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(g, cs, (int)(unsigned long)lbl_40_data_11D90)) {
        gfTask* task = getTask__6gfTaskFi(cs->taskId);
        ftManager* m = g_ftManager;
        int e = getEntryIdFromTaskId__9ftManagerFiPi(m, task->taskId, 0);
        signed char pn;
        if (e == -1) pn = -1;
        else {
            int p = getPlayerNo__9ftManagerFi(m, e);
            pn = p < 4 ? (signed char)p : -1;
        }
        if ((pn == 0 || g->f158->c == 0) && g->f14C == 0) {
            if (flag) {
                float r = mtSqrtf__Ff(g->f158->a * g->f158->a - g->f150 * (g->f158->b * g->f150));
                g->f154 = r;
                if (g->f158->a < lbl_40_rodata_728) g->f154 = -(float)(double)r;
                g->f14E = 1;
            }
            float t = -g->f150 * g->f158->b;
            float n = g->f154 + t;
            double at = fabs(t);
            double an = fabs(n);
            g->f154 = n;
            if ((float)an <= (float)at) g->f154 = lbl_40_rodata_728;
            g->f14C = 1;
        }
    }
}
