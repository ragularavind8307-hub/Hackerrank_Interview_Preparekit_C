string twoStrings(string s1, string s2) {
    int hash[26]={0};
    for(int i=0;s1[i]!='\0';i++){
        hash[s1[i]-'a']=1;
    }
    for(int i=0;s2[i]!='\0';i++){
        if(hash[s2[i]-'a']==1){
            return "YES";
        }
    }
    return "NO";
}
