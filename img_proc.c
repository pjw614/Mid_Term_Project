/*
 * img_proc.c
 *
 *  Created on: Apr 29, 2015
 *      Author: user
 */
#include "img_proc.h"

void rgb2ycbcr(char *image, int cols, int rows){
float T[3][3] = {{ .299,   .587,    .114},
       {-.169,  -.334,    .5},
       {.5,      .419,    -.081}};
   float offset[3] = {0, 128, 128};
   float temp_pixel[3];

   int i,j;
   char *pix;
   for (j = 0; j < rows; ++j){
       for (i = 0; i < cols; ++i){
           pix = &image[j * cols * 3 + i * 3];
           temp_pixel[0] =      T[0][0] * pix[0] +
           T[0][1] * pix[1] +
           T[0][2] * pix[2] +
           offset[0];
           temp_pixel[1] =  T[1][0] * pix[1] +
           T[1][1] * pix[1] +
           T[1][2] * pix[2] +
           offset[1];
           temp_pixel[2] =  T[2][0] * pix[2] +
           T[2][1] * pix[1] +
           T[2][2] * pix[2] +
           offset[2];

           pix[0] = (char)temp_pixel[0];
           pix[1] = (char)temp_pixel[1];
           pix[2] = (char)temp_pixel[2];
       }
   }
}

void ycbcr2rgb(char *input, int cols, int rows){
	 float Ti[3][3] = {{ 1,   0.0,     1.402},
	        { 1,  -0.344,  -0.714},
	        { 1,   1.772,   0.0}};
	    float offset[3] = {0, 128, 128};
	    float temp_pixel[3];

	    int i,j;
	    char *pix;
	    for (j = 0; j < rows; ++j){
	        for (i = 0; i < cols; ++i){
	            pix = &input[j * cols * 3 + i * 3];
	            temp_pixel[0] =      Ti[0][0] * (pix[0] - offset[0]) +
	            Ti[0][1] * (pix[1] - offset[1]) +
	            Ti[0][2] * (pix[2] - offset[2]);
	            temp_pixel[1] =  Ti[1][0] * (pix[1] - offset[1]) +
	            Ti[1][1] * (pix[1] - offset[1]) +
	            Ti[1][2] * (pix[2] - offset[2]);
	            temp_pixel[2] =  Ti[2][0] * (pix[2] - offset[2]) +
	            Ti[2][1] * (pix[1] - offset[1]) +
	            Ti[2][2] * (pix[2] - offset[2]);

	            pix[0] = (char)temp_pixel[0];
	            pix[1] = (char)temp_pixel[1];
	            pix[2] = (char)temp_pixel[2];
	        }
	    }
}


