//
//  jkReadCsv.h
//  NeuralNet
//
//  Created by JeiKei on 2016. 12. 12..
//  Copyright © 2016년 JeiKei. All rights reserved.
//

#ifndef jkReadCsv_h
#define jkReadCsv_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jkReadData {
    int n_row;
    int n_column;
    char file_name[512];
    double **data;
} jkReadData;

jkReadData* jkRead_csv(char *fileName);
void jkRead_free(jkReadData *data);
void jkWrite_csv(jkReadData *data, char *fileName);
void jkWrite_csv_double(double **data, int n_row, int n_column, char *fileName);
#endif /* jkReadCsv_h */
