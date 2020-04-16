
int main(void)
{
    string str;

    getline(cin,str);
    
    int left = 0,right =str.size()-1;

    while(left<right)
    {
        swap(str[left++],str[right--]);
    }
    

    cout<<str<<endl;

    return 0;
}