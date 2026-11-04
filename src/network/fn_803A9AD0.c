#pragma force_active on
typedef struct { unsigned char *ptr; char pad[8]; unsigned int type; } State;
extern char lbl_8053B248[];
void fn_803A9AD0(State *state, short count)
{
    short i;
    short offset = 0;
    unsigned char *p;
    if (state->type == 1) {
        p = state->ptr;
        while (count != 0) {
            if ((*(int (**)(int, int))(lbl_8053B248 + 0x30))((signed char)*p, 1)) offset++;
            offset++;
            count--;
        }
    } else {
        unsigned short *p2 = (unsigned short *)state->ptr;
        i = 0;
        while (i < count) {
            int n = (*(int (**)(unsigned short *))(lbl_8053B248 + 0x34))(p2);
            p2 += n;
            i++;
            offset += (short)n;
        }
    }
    state->ptr += offset;
}