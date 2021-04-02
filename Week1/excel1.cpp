int titleToNumber(string columnTitle) {
        long columnNum = 0;
        int n = columnTitle.size();
        for(int i = 0; i < n; i++)
        {
            columnNum *= 26;
            columnNum += columnTitle[i] - 'A' + 1;
        }
        return columnNum;
    }
