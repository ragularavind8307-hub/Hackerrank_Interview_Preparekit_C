int* freqQuery(int queries_rows, int queries_columns, int** queries, int* result_count) {
    int size = queries_rows * 2 + 1;

    int *keys = malloc(size * sizeof(int));
    int *valfreq = calloc(size, sizeof(int));
    int *countfreq = calloc(queries_rows + 1, sizeof(int));

    for (int i = 0; i < size; i++)
        keys[i] = -1;

    int *result = malloc(queries_rows * sizeof(int));
    int resultSize = 0;

    for (int i = 0; i < queries_rows; i++)
    {
        int type = queries[i][0];
        int value = queries[i][1];

        int index = (unsigned int)value % size;

        while (keys[index] != -1 && keys[index] != value)
        {
            index = (index + 1) % size;
        }

        if (keys[index] == -1)
            keys[index] = value;

        if (type == 1)
        {
            int old = valfreq[index];

            if (old > 0)
                countfreq[old]--;

            valfreq[index]++;

            countfreq[valfreq[index]]++;
        }

        else if (type == 2)
        {
            int old = valfreq[index];

            if (old > 0)
            {
                countfreq[old]--;

                valfreq[index]--;

                if (valfreq[index] > 0)
                    countfreq[valfreq[index]]++;
            }
        }

        else if (type == 3)
        {
            if (value <= queries_rows &&
                countfreq[value] > 0)
                result[resultSize++] = 1;
            else
                result[resultSize++] = 0;
        }
    }

    free(keys);
    free(valfreq);
    free(countfreq);

    *result_count = resultSize;

    return result;
}
