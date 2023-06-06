int Solution::atoi(const string s) {
     int len = s.size();
        long long int num = 0;
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i]-'0');
            if(num>INT_MAX && !negative) return INT_MAX;
            if(num>INT_MAX && negative) return INT_MIN;

            i++;
        }
        num = negative ? -num : num;
        
       
        return int(num);
}
