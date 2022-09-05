#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <png.h>
#include <math.h>

png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers = NULL;

void read_png_file(char *filename,int *width,int *height) {
FILE *fp = fopen(filename, "rb");

png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
if(!png) abort();

png_infop info = png_create_info_struct(png);
if(!info) abort();

if(setjmp(png_jmpbuf(png))) abort();

png_init_io(png, fp);

png_read_info(png, info);

*width = png_get_image_width(png, info);
*height = png_get_image_height(png, info);
color_type = png_get_color_type(png, info);
bit_depth = png_get_bit_depth(png, info);

if(bit_depth == 16)
png_set_strip_16(png);

if(color_type == PNG_COLOR_TYPE_PALETTE)
png_set_palette_to_rgb(png);

if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
png_set_expand_gray_1_2_4_to_8(png);

if(png_get_valid(png, info, PNG_INFO_tRNS))
png_set_tRNS_to_alpha(png);

if(color_type == PNG_COLOR_TYPE_RGB ||
color_type == PNG_COLOR_TYPE_GRAY ||
color_type == PNG_COLOR_TYPE_PALETTE)
png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

if(color_type == PNG_COLOR_TYPE_GRAY ||
color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
png_set_gray_to_rgb(png);

png_read_update_info(png, info);

if (row_pointers) abort();

row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * *height);
for(int y = 0; y < (*height); y++) {
row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
}

png_read_image(png, row_pointers);

fclose(fp);

png_destroy_read_struct(&png, &info, NULL);
}

void write_png_file(char *filename,int *width,int *height) {
int y;

FILE *fp = fopen(filename, "wb");
if(!fp) abort();

png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
if (!png) abort();

png_infop info = png_create_info_struct(png);
if (!info) abort();

if (setjmp(png_jmpbuf(png))) abort();

png_init_io(png, fp);

png_set_IHDR(
png,
info,
*width, *height,
8,
PNG_COLOR_TYPE_RGBA,
PNG_INTERLACE_NONE,
PNG_COMPRESSION_TYPE_DEFAULT,
PNG_FILTER_TYPE_DEFAULT
);
png_write_info(png, info);

if (!row_pointers) abort();

png_write_image(png, row_pointers);
png_write_end(png, NULL);

for(int y = 0; y < (*height); y++) {
free(row_pointers[y]);
}
free(row_pointers);

fclose(fp);

png_destroy_write_struct(&png, &info);
}
float check_average_1(int height_1,int width_1,int height_2, int width_2,unsigned first_png[height_1][width_1],unsigned second_png[height_2][width_2])
{
  float average = 0;
  for(float prec = 0;prec < 1; prec = prec +0.010)
  {
    unsigned summ_1 = 0;
    unsigned summ_2 = 0;
    float average_1;
    float average_2;
    for(int i = 0;i<(height_1*(1-prec));i++)
    {
      for(int j = 0;j<(width_1*(1-prec));j++)
      {
        summ_1+=first_png[i][j];
      }
    }

    for(int i = 0;i<(height_2*(1-prec));i++)
    {
      for(int j = 0;j<(width_2*(1-prec));j++)
      {
        summ_2+=second_png[i][j];
      }
    }
    average_1 = summ_1 /(height_1*width_1*(1-prec)*(1-prec));
    average_2 = summ_2/(height_2*width_2*(1-prec)*(1-prec));
    float boof;
    if((average_1==0.000)&&(average_2==0.000))
    {
      boof = 0.000;
    }
    else
    {
      if(average_1!=0.000)
      {
        boof = (average_1-average_2)/average_1;
      }
      else
      {
        boof = (average_2-average_1)/average_2;
      }
    }
    average+=boof*boof;
  }
    return sqrt(average);
}
float check_average_2(int height_1,int width_1,int height_2, int width_2,unsigned first_png[height_1][width_1],unsigned second_png[height_2][width_2])
{
  float average = 0;
  for(float prec = 0;prec < 1; prec = prec +0.010)
  {
    unsigned summ_1 = 0;
    unsigned summ_2 = 0;
    float average_1;
    float average_2;
    for(int i = (int)(height_1*(prec));i<height_1;i++)
    {
      for(int j = (int)(width_1*(prec));j<width_1;j++)
      {
        summ_1+=first_png[i][j];
      }
    }

    for(int i = (int)(height_2*(prec));i<height_2;i++)
    {
      for(int j = (int)(width_2*(prec));j<width_2;j++)
      {
        summ_2+=second_png[i][j];
      }
    }
    average_1 = summ_1 /(height_1*width_1*(1-prec)*(1-prec));
    average_2 = summ_2/(height_2*width_2*(1-prec)*(1-prec));
    float boof;
    if((average_1==0.000)&&(average_2==0.000))
    {
      boof = 0.000;
    }
    else
    {
      if(average_1!=0.000)
      {
        boof = (average_1-average_2)/average_1;
      }
      else
      {
        boof = (average_2-average_1)/average_2;
      }
    }
    average+=boof*boof;
  }
    return sqrt(average);
}
float check_average_3(int height_1,int width_1,int height_2, int width_2,unsigned first_png[height_1][width_1],unsigned second_png[height_2][width_2])
{
  float average = 0;
  for(float prec = 0;prec < 1; prec = prec +0.010)
  {
    unsigned summ_1 = 0;
    unsigned summ_2 = 0;
    float average_1;
    float average_2;
    for(int i = 0;i<height_1*(1-prec);i++)
    {
      for(int j = (int)(width_1*(prec));j<width_1;j++)
      {
        summ_1+=first_png[i][j];
      }
    }

    for(int i = 0;i<height_2*(1-prec);i++)
    {
      for(int j = (int)(width_2*(prec));j<width_2;j++)
      {
        summ_2+=second_png[i][j];
      }
    }
    average_1 = summ_1 /(height_1*width_1*(1-prec)*(1-prec));
    average_2 = summ_2/(height_2*width_2*(1-prec)*(1-prec));
    float boof;
    if((average_1==0.000)&&(average_2==0.000))
    {
      boof = 0.000;
    }
    else
    {
      if(average_1!=0.000)
      {
        boof = (average_1-average_2)/average_1;
      }
      else
      {
        boof = (average_2-average_1)/average_2;
      }
    }
    average+=boof*boof;
  }
    return sqrt(average);
}
float check_average_4(int height_1,int width_1,int height_2, int width_2,unsigned first_png[height_1][width_1],unsigned second_png[height_2][width_2])
{
  float average = 0;
  for(float prec = 0;prec < 1; prec = prec +0.010)
  {
    unsigned summ_1 = 0;
    unsigned summ_2 = 0;
    float average_1;
    float average_2;
    for(int i = (int)(height_1*(prec));i<height_1;i++)
    {
      for(int j = 0;j<width_1*(1-prec);j++)
      {
        summ_1+=first_png[i][j];
      }
    }

    for(int i = (int)(height_2*(prec));i<height_2;i++)
    {
      for(int j = 0;j<width_2*(1-prec);j++)
      {
        summ_2+=second_png[i][j];
      }
    }
    average_1 = summ_1 /(height_1*width_1*(1-prec)*(1-prec));
    average_2 = summ_2/(height_2*width_2*(1-prec)*(1-prec));
    float boof;
    if((average_1==0.000)&&(average_2==0.000))
    {
      boof = 0.000;
    }
    else
    {
      if(average_1!=0.000)
      {
        boof = (average_1-average_2)/average_1;
      }
      else
      {
        boof = (average_2-average_1)/average_2;
      }
    }
    average+=boof*boof;
  }
    return sqrt(average);
}
int main(int argc, char *argv[]){
if(argc!=3){
  puts("ERROR_not_enough_args");
  return 0;
}
  int width, height;
  read_png_file(argv[1],&width,&height);
  unsigned first_png[height][width];
  for(int i = 0;i<height;i++)
  {
    for(int j = 0;j<width;j++)
    {
      first_png[i][j] = row_pointers[i][j];
    }
}
  int width2, height2;
  row_pointers = NULL;
  read_png_file(argv[2],&width2,&height2);
  unsigned second_png[height2][width2];
  for(int i = 0;i<height2;i++)
  {
    for(int j = 0;j<width2;j++)
    {
      second_png[i][j] = row_pointers[i][j];
  }
}
  float result_1 = check_average_1(height,width,height2,width2,first_png,second_png);
  float result_2 = check_average_2(height,width,height2,width2,first_png,second_png);
  float result_3 = check_average_3(height,width,height2,width2,first_png,second_png);
  float result_4 = check_average_4(height,width,height2,width2,first_png,second_png);
  float result = sqrt(pow(result_1,2)+pow(result_2,2)+pow(result_3,2)+pow(result_4,2));
  printf("Итоговая разница - %.2f %%\n", result*100);
return 0;
}
