   string convertToTitle(int columnNumber) {
       string ans="";
       int i=1;
       while(columnNumber>0){
        int k = (columnNumber - 1) % 26 + 1;
        ans= char(k + int('A')-1) +ans;
        columnNumber = (columnNumber - 1) / 26;
       }
       return ans;
    }
