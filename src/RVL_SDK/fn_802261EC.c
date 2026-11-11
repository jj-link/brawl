#pragma force_active on

#pragma fp_contract off
extern double fn_80400D94(double);
extern float lbl_8059ED40;
extern const float lbl_8059ED48;
extern const float lbl_805A39E8;
extern const float lbl_805A39F8;
typedef struct 
{
  float x;
  float y;
  signed char flag;
  char pad[3];
} Elem;
typedef struct 
{
  float x;
  float y;
} Vec2;
inline static float dot2(const Vec2 *b, const Vec2 *a)
{
  return (a->x * b->x) + (a->y * b->y);
}

int fn_802261EC(void *base)
{
  float scale;
  float best = lbl_8059ED48;
  char *new_var;
  float threshold;
  Elem *new_var4[2];
  char *new_var2;
  Elem *outer = (Elem *) (((char *) base) + 0xC4);
  Elem *inner;
  Elem *best_first;
  Elem *best_second;
  char *new_var3;
  threshold = lbl_805A39E8;
  scale = lbl_805A39F8;
  new_var4[0] = (Elem *) (((char *) base) + 0xE8);
  do
  {
    if (outer->flag == 0)
    {
      new_var = (char *) base;
      inner = outer + 1;
      new_var4[1] = (Elem *) (new_var + 0xE8);
      do
      {
        if (inner->flag == 0)
        {
          float dy;
          float dx = inner->x - outer->x;
          dy = inner->y - outer->y;
          {
            float inverse = scale / ((float) fn_80400D94((dx * dx) + (dy * dy)));
            float speed;
            Vec2 projection;
            dx *= inverse;
            new_var = (char *) base;
            dy *= inverse;
            new_var2 = new_var + 0xB4;
            new_var3 = new_var + 0xB4;
            projection.x = ((*((float *) (((char *) base) + 0xB0))) * dx) + ((*((float *) new_var3)) * dy);
            projection.y = ((*((float *) new_var2)) * dx) - ((*((float *) (new_var + 0xB0))) * dy);
            speed = (*((float *) (((char *) base) + 0x510))) * inverse;
            if ((!(speed <= (*((float *) (new_var + 0x514))))) && (!(speed >= lbl_8059ED40)))
            {
              float value = dot2(&projection, (Vec2 *) (new_var + 0x4B8));
              if (value < threshold)
              {
                float magnitude = -value;
                if (magnitude > best)
                {
                  best = magnitude;
                  best_first = inner;
                  best_second = outer;
                }
              }
              else
                if (value > best)
              {
                best = value;
                best_first = outer;
                best_second = inner;
              }
            }
          }
        }
        inner++;
      }
      while (inner <= new_var4[1]);
    }
    outer++;
  }
  while (outer < new_var4[0]);
  if (best == lbl_8059ED48)
  {
    return 0;
  }
  *((Elem *) (((char *) base) + 0xF4)) = *best_first;
  *((Elem *) (new_var + 0x100)) = *best_second;
  return 2;
}
