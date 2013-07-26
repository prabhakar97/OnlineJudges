#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

void balanceAndPrint(multiset<int> &set1, multiset<int> &set2); 

int main() {
    int n;
    cin>>n;
    char ch;
    int num;
    multiset<int> set1;
    multiset<int> set2;
    for(int i=0; i<n; i++) {
        cin.ignore();
        cin>>ch;
        cin>>num;
        if(ch=='r') {
            multiset<int>::iterator iter1 = set1.find(num);
            multiset<int>::iterator iter2 = set2.find(num);
            if(iter1 != set1.end() || iter2 != set2.end()) {
                if(iter1 == set1.end())
                    set2.erase(iter2);
                else
                    set1.erase(iter1);
                balanceAndPrint(set1, set2);
            }
            else
                cout<<"Wrong!";
        }
        else {
            if(set1.size() == 0)
                set1.insert(num);
            else {
                if(*(set1.rbegin()) > num)
                    set1.insert(num);
                else
                    set2.insert(num);
            }
            balanceAndPrint(set1, set2);
        }
        if(i!=n-1)
            cout<<endl;
       }
       return 0;
}

void balanceAndPrint(multiset<int> &set1, multiset<int> &set2) {
    if(set1.size() > set2.size()) {
        if((set1.size() - set2.size()) > 1) {
            set2.insert(*(set1.rbegin()));
            multiset<int>::iterator iter=set1.end();
            iter--;
            set1.erase(iter);
        }
    }
    else if(set2.size() > set1.size()) {
        if((set2.size() - set1.size()) > 1) {
            set1.insert(*(set2.begin()));
            set2.erase(set2.begin());
        }
    }
    if(set1.size() > set2.size()) {
        cout<<*(set1.rbegin());
    }
    else if(set2.size() > set1.size())
        cout<<*(set2.begin());
    else if((set1.size() == set2.size()) && set1.size() == 0)
        cout<<"Wrong!";
    else{
        int sum = *(set1.rbegin()) + *(set2.begin());
        if(sum & 1) {
            cout<<showpoint<<fixed<<setprecision(1);
            cout<<(double)sum/2;
        }
        else
            cout<<sum/2;
    }
    /*for(multiset<int>::iterator iter=set1.begin(); iter!=set1.end(); iter++)
        cout<<*iter<<" ";
    cout<<"   ";
    for(multiset<int>::iterator iter=set2.begin(); iter!=set2.end(); iter++)
        cout<<*iter<<" ";
    cout<<endl;
    */
}
