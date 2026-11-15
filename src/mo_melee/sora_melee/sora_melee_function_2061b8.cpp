#include <types.h>
#include <ai/ai_mgr.h>
#pragma force_active on
struct AiConstantPool { f32 f00[34]; f64 d88; f64 d90; f32 f98[48]; f64 d158; f64 d160; f32 f168[68]; };
struct AiFighterState { char pad0[0x5C]; Vec2f vector5C; char pad64[0x50]; s32 unkB4; char padB8[4]; u8* unkBC; u8 unkC0; char padC1[0xF9]; u8 unk1BA; };
struct AiScript { char pad0[0xE0]; f32 unkE0; };
struct AiInput { char pad0[0x42]; s8 fighterId; char pad43[1]; AiScript* script; char pad48[8]; s32 unk50; s32 unk54; };
extern "C" {
extern const AiConstantPool lbl_27_rodata_2CF0;
AiFighterState* fn_27_1F1F58(s8*);
void fn_27_1F9FBC(AiInput*,s32,s8*,u32,s32);
s32 fn_27_20B568(AiFighterState*);
void fn_27_2106E0(AiScript*,f32*,f32*,s32);
void fn_27_21062C(AiScript*,f32,f32,u8*,u8*);
s32 fn_27_1ED3D8(aiMgr*,f32,f32,Vec2f*,Vec2f*,s32,s32,s32);
}
extern "C" s32 fn_27_2061B8(AiInput* self, Vec2f* out) {
    f32 temp_f1, temp_f2;
    s8 sp8; s8* idPtr;
    const AiConstantPool* constants=&lbl_27_rodata_2CF0;
    AiFighterState* fighter=fn_27_1F1F58(&self->fighterId);
    if(fighter->unk1BA!=0xC){sp8=-1;idPtr=&sp8;fn_27_1F9FBC(self,fn_27_20B568(fighter)!=0?7:3,idPtr,0,0);return 1;}
    if(self->unk50==0){
        if(fighter->unkC0!=2&&fighter->unkB4!=0xB3&&fighter->unkB4!=0xB4&&fighter->unkB4!=0xB5&&fighter->unkB4!=0xBC){self->script->unkE0=fighter->vector5C.m_x;self->unk54=0;self->unk50=2;}
        else{Vec2f sp20;fn_27_2106E0(self->script,&sp20.m_x,&sp20.m_y,0);fn_27_21062C(self->script,sp20.m_x,sp20.m_y,fighter->unkBC,0);self->unk50=1;}
    }
    switch(self->unk50){
    case 1:{
        Vec2f sp18,sp10;
        out->m_x=fighter->vector5C.m_x>self->script->unkE0?constants->f98[25]:constants->f00[8];
        if(fighter->unkB4!=0xB3&&fighter->unkB4!=0xB4&&fighter->unkB4!=0xB5&&fighter->unkB4!=0xBC){
            temp_f1=constants->f00[4];temp_f2=temp_f1+fighter->vector5C.m_y;
            sp10.m_x=fighter->vector5C.m_x;sp10.m_y=temp_f2;temp_f1=fighter->vector5C.m_y;sp18.m_x=fighter->vector5C.m_x;sp18.m_y=temp_f1;
            if(fn_27_1ED3D8(g_aiMgr,temp_f1,sp10.m_x,&sp18,&sp10,0x1C,0,0)==0){self->unk54=0;self->unk50=self->unk50+1;break;}
        }
        if(self->unk54>=0x32)self->unk50=0;break;
    }
    case 2:{f32 diff=self->script->unkE0-fighter->vector5C.m_x;if(diff>constants->f00[4])out->m_x=constants->f00[8];else if(diff<constants->f98[0])out->m_x=constants->f98[25];out->m_y=constants->f00[8];if(self->unk54>=0x10)self->unk50=0;break;}
    }
    return 1;
}