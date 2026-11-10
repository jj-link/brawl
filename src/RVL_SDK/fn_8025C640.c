#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct 
{
  float tables[4][64];
  char pad[0x29c];
  u8 *input;
} JpegState;
extern JpegState *lbl_805A0D44;
extern const u8 lbl_8040DAF8[];
extern const double lbl_8040DB48[];
int fn_8025C640(void)
{
  float values[64];
  u16 length;
  u16 i;
  long long new_var;
  u16 j;
  unsigned int table;
  u8 *p = lbl_805A0D44->input;
  length = p[1] | (((u16) p[0]) << 8);
  lbl_805A0D44->input = p + 2;
  length -= 2;
  new_var = 0;
  do
  {
    table = *(lbl_805A0D44->input++);
    {
      int n;
      int k = new_var;
      for (n = new_var; n < 8; n++, k += 8)
      {
        values[*(lbl_8040DAF8 + ((u16) k))] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 1]] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 2]] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 3]] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 4]] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 5]] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 6]] = *(lbl_805A0D44->input++);
        values[lbl_8040DAF8[((u16) k) + 7]] = *(lbl_805A0D44->input++);
      }

    }
    i = 0;
    for (j = new_var; j < 8; j++)
    {
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[new_var] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[1] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[2] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[3] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[4] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[5] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[6] * (values[i] * lbl_8040DB48[j]);
      i++;
      lbl_805A0D44->tables[(u16) table][i] = lbl_8040DB48[7] * (values[i] * lbl_8040DB48[j]);
      i++;
    }

    length -= 0x41;
  }
  while (length != (i * new_var));
  return 0;
}
