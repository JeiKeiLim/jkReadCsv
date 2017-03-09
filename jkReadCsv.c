//
//  jkReadCsv.c
//  NeuralNet
//
//  Created by JeiKei on 2016. 12. 12..
//  Copyright © 2016년 JeiKei. All rights reserved.
//

#include "jkReadCsv.h"

jkReadData* jkRead_csv(char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL)
        return NULL;
 
    int i, j,k;
    char buf[64];
    jkReadData *data = (jkReadData *)malloc(sizeof(jkReadData));
    memcpy(data->file_name, fileName, 512);
    data->n_row = 0;
    data->n_column = 1;
    
    char c;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n')
            data->n_row++;
        
        if(c == ',' && data->n_row < 1)
            data->n_column++;
    }
    
    data->data = (double **)malloc(data->n_row * sizeof(double *));
    double *_data = (double *)malloc(data->n_row * data->n_column * sizeof(double));
    
    for(i=0; i<data->n_row; i++)
    {
        data->data[i] = &_data[i*data->n_column];
//        data->data[i] = (double *)malloc(data->n_column * sizeof(double));
    }
    
    i = 0;
    j = 0;
    k = 0;
    rewind(fp);
    while((c = fgetc(fp)) != EOF)
    {
        if(c == ',')
        {
            buf[i] = '\0';
            i = 0;
            data->data[j][k++] = atof(buf);
        }
        else if(c == '\n')
        {
            buf[i] = '\0';
            i = 0;
            data->data[j][k++] = atof(buf);
            
            j++;
            k = 0;
        }
        else
            buf[i++] = c;
        
    }
    
    fclose(fp);
    
    return data;
}

void jkRead_free(jkReadData *data)
{
    free(data->data[0]);
    free(data->data);
    free(data);
}

void jkWrite_csv_double(double **data, int n_row, int n_column, char *fileName)
{
    FILE *fp = fopen(fileName, "w");
    int i,j;
    
    if(fp == NULL)
        return;
    for(i=0; i<n_row; i++)
    {
        fprintf(fp, "%f", data[i][0]);
        for(j=1; j<n_column; j++)
        {
            fprintf(fp, ",%f", data[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void jkWrite_csv(jkReadData *data, char *fileName)
{
    jkWrite_csv_double(data->data, data->n_row, data->n_column, fileName);
}


void jkReadData_printProperty(jkReadData *data)
{
    printf("File name : %s\nColumn : %d\nRow : %d\n", data->file_name, data->n_column, data->n_row);
}


