# jkReadCsv
Simple implementation of reading csv file.

## Structure definition
<B>jkReadData</B> offers information of read data.
- <B>n_row</B> : number of row
- <B>n_column</B> : number of column
- <B>file_name</B> : read file name.
- <B>**data</B> : read data. Its size will be [<B>n_row</B>]X[<B>n_column</B>]

## Function description
jkReadData* <B>jkRead_csv</B>(char <B>*fileName</B>)
- Read csv data and returns <B>jkReadData</B> structure.


void <B>jkRead_free</B>(jkReadData <B>*data</B>)
- Free memory allocation



# Usage example
```C
jkReadData *data;
data = jkRead_csv("file_name.csv");

int i,j;

for(i=0; i<data->n_row; i++)
{
    for(j=0; j<data->n_column; j++)
    {
        printf("data[%d][%d] = %f\n", i,j, data->data[i][j]);
    }
}

jkRead_free(data);
```

